#pragma once

#include "Board.hpp"
#include <ostream>
#include <string>
#include "City.hpp"
#include <unordered_set>
#include "Player.hpp"

using namespace std;
using namespace pandemic;

class Dispatcher:public Player{
    
    public:
        Dispatcher(Board &b, City c);
        virtual Player& fly_direct(City city);
        virtual string role();
};
