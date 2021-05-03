
#include "Board.hpp"
#include <iostream>
#include <string>
#include "City.hpp"
#include <unordered_set>
#include "Player.hpp"
#include "Scientist.hpp"
using namespace std;
using namespace pandemic;

Scientist::Scientist (Board &b, City c,int n) : Player(b,c), droped_cards(n)
{}

Player& Scientist::discover_cure(Color color)
{
        if(!(board->cities.at(curr_city).rsrch_st))
        {
            throw invalid_argument("There is no a research station in this city");
        }
        
        if(!board->diseases.at(color))
        {   
            unordered_set<City>::iterator it = cards.begin();
            int count=0;
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


string Scientist::role()
{
    return "Scientist";
}
