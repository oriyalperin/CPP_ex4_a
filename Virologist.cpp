
#include "Board.hpp"
#include <iostream>
#include <string>
#include "City.hpp"
#include <unordered_set>
#include "Player.hpp"
#include "Virologist.hpp"
using namespace std;
using namespace pandemic;

Virologist::Virologist (Board &b, City c) : Player(b,c)
{}

Player& Virologist::treat(City city)
{
        
        if(board->cities.at(city).cubes==0)
        {
            throw out_of_range("The current city is free of contamination");
        }
        bool in_cards =cards.find(city)!=cards.end();
        if(curr_city!=city && !in_cards)
        {
            throw out_of_range("The current city card is missing");
        }

        if(board->diseases.at(board->cities.at(city).color))
        {
            board->cities.at(city).cubes=0;
        }
        else
        {
            (*board)[city]-=1;
        }
        if(curr_city!=city && in_cards)
        {
            throw_card(city);
        }
    return *this;
}

string Virologist::role()
{
    return "Virologist";
}
