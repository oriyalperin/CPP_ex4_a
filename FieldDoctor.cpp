
#include "Board.hpp"
#include <iostream>
#include <string>
#include "City.hpp"
#include <unordered_set>
#include "Player.hpp"
#include "FieldDoctor.hpp"
using namespace std;
using namespace pandemic;

FieldDoctor::FieldDoctor (Board &b, City c) : Player(b,c)
{}


Player& FieldDoctor::treat(City city)
{
       
       if(curr_city!=city && !is_nbr(city))
        {
            throw invalid_argument("This city is inaccessible");
        }
        
        if(board->cities.at(city).cubes==0)
        {
            throw out_of_range("The current city is free of contamination");
        }
        if(board->diseases.at(board->cities.at(city).color))
        {
            board->cities.at(city).cubes=0;
        }
        else
        {
            (*board)[city]-=1;

        }
        return *this;
    return *this;
}

string FieldDoctor::role()
{
    return "FieldDoctor";
}
