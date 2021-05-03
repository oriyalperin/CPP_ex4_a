#pragma once

#include "Board.hpp"
#include <ostream>
#include <string>
#include "City.hpp"
#include <unordered_set>
#include "Player.hpp"

using namespace std;
using namespace pandemic;

class Virologist:public Player{
    
    public:
        Virologist(Board &b, City c);
        virtual Player& treat(City city);
        virtual string role();
};
