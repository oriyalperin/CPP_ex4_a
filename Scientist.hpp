#pragma once

#include "Board.hpp"
#include <ostream>
#include <string>
#include "City.hpp"
#include <unordered_set>
#include "Player.hpp"

using namespace std;
using namespace pandemic;

class Scientist:public Player{

    private:
        int droped_cards;
    public:
        Scientist(Board &b, City c,int n);
        virtual Player& discover_cure(Color color); 
        virtual string role();
};
