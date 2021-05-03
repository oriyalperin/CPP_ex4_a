#pragma once

#include "Board.hpp"
#include <ostream>
#include <string>
#include "City.hpp"
#include <unordered_set>
#include "Player.hpp"

using namespace std;
using namespace pandemic;

class GeneSplicer:public Player{

    public:
        GeneSplicer(Board &b, City c);
        virtual Player& discover_cure(Color color); 
        virtual string role();
};
