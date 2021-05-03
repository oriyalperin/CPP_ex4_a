#include <iostream>
#include "Board.hpp"
#include <string>
#include "City.hpp"
#include <unordered_set>
#include "Player.hpp"
using namespace std;
using namespace pandemic;

    Player::Player(Board &b,City c)
    {
        board=&b;
        curr_city=c;
        //colors.fill(0);
    }

    void Player::throw_card(City city)
    {
        cards.erase(city);
        colors.at((unsigned)board->cities.at(city).color)--;
    }

    Player& Player::remove_cards()
    {
        cards.clear();
        return *this;
    }

    bool Player::is_nbr(City city)
    {
        return (board->cities.at(curr_city).nbrs.find(city)!=board->cities.at(curr_city).nbrs.end());
    }
    Player& Player::drive(City city)
    {
        if( is_nbr(city))
        {
            curr_city=city;
        }
        else
        {
            throw invalid_argument("This city is inaccessible");
        }
        return *this;
        
    }

    Player& Player::fly_direct(City city)
    {
        if( cards.find(city)!= cards.end())
        {
            throw_card(city);
            curr_city=city;
        }
        else
        {
            throw invalid_argument("This city is inaccessible");
        }
        return *this;
    }
    Player& Player::fly_charter(City city)
    {
        if( cards.find(curr_city)!= cards.end())
        {
            throw_card(curr_city);
            curr_city=city;
        }
        else
        {
            throw invalid_argument("The current city card is missing");
        }
        return *this;

    }
    Player& Player:: fly_shuttle(City city)
    {

        if(board->cities.at(curr_city).rsrch_st && board->cities.at(city).rsrch_st)
        {
            curr_city=city;
        }
        else
        {
            throw invalid_argument("This city is inaccessible");
        }
        
        return *this;

    }


    Player& Player::build()
    {
        if(board->cities.at(curr_city).rsrch_st)
        {
            throw invalid_argument("There is already a research station in this city");
        }
        if(cards.find(curr_city)==cards.end())
        {
            throw invalid_argument("The current city card is missing");
        }
        throw_card(curr_city);
        board->cities.at(curr_city).rsrch_st=true;
        //cout<<board<<endl;
        return *this;
    }

    Player& Player::discover_cure(Color color)
    {
        if(!(board->cities.at(curr_city).rsrch_st))
        {
            throw invalid_argument("There is no a research station in this city");
        }
        
        if(!board->diseases.at(color))
        {   
            unordered_set<City>::iterator it = cards.begin();
            int count=0;
            const int droped_cards=5;
            if(Player::amnt_by_clr(color)>=droped_cards)
            {
                while(it!=cards.end() && count<droped_cards)
                {
                    if(board->cities.at(*it).color==color)
                    {
                        City city=*it;
                        it++;
                        throw_card(city);
                        count++;
                    }
                    else 
                    {
                        it++;
                    }
                }
                    board->diseases.at(color)=true;
            }
            else
            {
                throw invalid_argument("There are no enough cards to discovre a cure");
            }
        }
        return *this;
    }

    Player& Player::treat(City city)
    {
        if(curr_city!=city)
        {
            throw invalid_argument("The current city is diffrent");
        }
        
        if(board->cities.at(city).cubes==0)
        {
            throw out_of_range("The current city is free of contamination");
        }
        if(board->diseases.at(board->cities.at(city).color))
        {
            //board->size_cubes()-= board->cities.at(city).cubes;
            board->cities.at(city).cubes=0;
        }
        else
        {
            (*board)[city]-=1;
           // cout<<board->cities.at(city).cubes<<endl;
            //board->size_cubes()-=1;
        }
        return *this;
    }

    int Player::amnt_by_clr(Color color)
    {
        return colors.at((unsigned)color);
    }


    Player& Player::take_card(City city)
    { 
        if(cards.find(city)==cards.end())
        {
            cards.insert(city);
            
            colors.at((unsigned)(board->cities.at(city).color))++;
        }
        return *this;
        
    }

    string Player::role()
    {
        return "Player";
    }

