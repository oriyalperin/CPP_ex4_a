
#include "Board.hpp"
#include <iostream>
#include <string>
#include "City.hpp"
#include <unordered_set>
#include "Player.hpp"
#include "Researcher.hpp"
using namespace std;
using namespace pandemic;

Researcher::Researcher (Board &b, City c) : Player(b,c)
{}

Player& Researcher::discover_cure(Color color)
{
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

string Researcher::role()
{
    return "Researcher";
}

