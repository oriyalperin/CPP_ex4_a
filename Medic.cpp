
#include "Board.hpp"
#include <iostream>
#include <string>
#include "City.hpp"
#include <unordered_set>
#include "Player.hpp"
#include "Medic.hpp"
using namespace std;
using namespace pandemic;

Medic::Medic (Board &b, City c) : Player(b,c)
{}

Player& Medic::drive(City city)
{
    Player::drive(city);
    (*board)[city]=0;
    return *this;
}
Player& Medic::fly_direct(City city)
{
    Player::fly_direct(city);
    (*board)[city]=0;
    return *this;
}
Player& Medic::fly_charter(City city)
{
    Player::fly_charter(city);
    (*board)[city]=0;
    return *this;
}
Player& Medic::fly_shuttle(City city)
{
    Player::fly_shuttle(city);
    (*board)[city]=0;
    return *this;
}

Player& Medic::treat(City city)
{
    if(curr_city!=city)
        {
            throw invalid_argument("The current city is diffrent");
        }
        
        if(board->cities.at(city).cubes==0)
        {
            throw out_of_range("The current city is free of contamination");
        }
        (*board)[city]=0;

    return *this;
}

string Medic::role()
{
    return "Medic";
}
