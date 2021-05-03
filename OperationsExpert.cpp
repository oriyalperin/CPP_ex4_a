
#include "Board.hpp"
#include <iostream>
#include <string>
#include "City.hpp"
#include <unordered_set>
#include "Player.hpp"
#include "OperationsExpert.hpp"
using namespace std;
using namespace pandemic;

OperationsExpert::OperationsExpert (Board &b, City c) : Player(b,c)
{}


Player& OperationsExpert::build()
{
    if(board->cities.at(curr_city).rsrch_st)
    {
        throw invalid_argument("There is already a research station in this city");
    }
    board->cities.at(curr_city).rsrch_st=true;
    return *this;
}


string OperationsExpert::role ()  
{
    return "OperationsExpert";
}
