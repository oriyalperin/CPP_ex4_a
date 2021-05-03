#pragma once
#include <ostream>
#include "Board.hpp"
#include <string>
#include "City.hpp"
#include <unordered_set>

using namespace std;
using namespace pandemic;

 class Player
    {
    protected:
        City curr_city;
        unordered_set<City> cards;
        array<int,4> colors{0};
        Board *board;
        int amnt_by_clr(Color color);
        void throw_card(City city);
        bool is_nbr(City city);
        Player(Board &b,City c);
    
    public:
        
        virtual Player& drive(City city);
        virtual Player& fly_direct(City city);
        virtual Player& fly_charter(City city);
        virtual Player& fly_shuttle(City city);
        virtual Player& build();
        virtual Player& discover_cure(Color color); 
        virtual Player& treat(City city);
        virtual string role();
        virtual Player& take_card(City city);
        virtual Player& remove_cards();

    } ;

    