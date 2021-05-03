
#include "Board.hpp"
#include <iostream>
#include <string>
#include "City.hpp"
#include <unordered_set>
#include "Player.hpp"
#include "GeneSplicer.hpp"
using namespace std;
using namespace pandemic;

GeneSplicer::GeneSplicer (Board &b, City c) : Player(b,c)
{}

Player& GeneSplicer::discover_cure(Color color)
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
            if(cards.size()>=droped_cards)
            {
                while(it!=cards.end() && count<droped_cards)
                {
                        City city=*it;
                        it++;
                        throw_card(city);
                        count++;
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

string GeneSplicer::role()
{
    return "GeneSplicer";
}
