/**
 * An example of how to write expected tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Oriya Alperin>
 * 
 * Date: 2021-05
 */

#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"
using namespace pandemic;

#include <string>
#include <algorithm>
using namespace std;

TEST_CASE("game1") {
    Board board;
    OperationsExpert oe{board,City::Atlanta};
    Dispatcher d{board,City::Baghdad};
    Researcher r{board,City::HongKong};
    Virologist v{board,City::London};
    Medic m{board,City::Madrid};
    Scientist s{board,City::Sydney,2};
    GeneSplicer gs{board,City::Tehran};
    FieldDoctor fd{board,City::Washington};
    CHECK(board.is_clean()==true);
    board[City::Tehran]=3; 
    CHECK(board[City::Tehran]==3);
    CHECK(board.is_clean()==false);
    board[City::Sydney]=4; 
    CHECK(board[City::Washington]==0); 
    board[City::Baghdad]=4; 
    board[City::London]=5; 
    board[City::Atlanta]=7; 
    board[City::Madrid]=3; 
    board[City::HongKong]=5; 
    board[City::MexicoCity]=4; 
    board[City::Miami]=4; 
    board[City::SanFrancisco]=5;
    board[City::Chicago]=6;
    board[City::Montreal]=3; 
    board[City::NewYork]=2;  
    board[City::Johannesburg]=1;
    oe.take_card(City::Chicago).
    take_card(City::MexicoCity).
    take_card(City::SanFrancisco).
    take_card(City::Montreal).
    take_card(City::NewYork). 
    take_card(City::Miami);//4 blue, 2 yellow
    oe.drive(City::Miami); //curr_city= miami
    oe.build(); //miami - V
    CHECK_THROWS(oe.discover_cure(Color::Yellow));
    fd.treat(City::Miami); // miami=3
    CHECK_THROWS(gs.build()); //doesnt have curr_city=Tehran card
    gs.take_card(City::Tehran);//in order to build a research station
    gs.build(); //Tehran - V
    gs.take_card(City::Milan).
    take_card(City::Osaka).
    take_card(City::Riyadh).
    take_card(City::Jakarta); //1 black, 2 red, 1 blue
    CHECK_THROWS(gs.discover_cure(Color::Yellow));
    gs.take_card(City::Algiers); //2 black, 2 red, 1 blue
    gs.discover_cure(Color::Yellow); // Yellow - V , gs - 0 cards
    oe.discover_cure(Color::Yellow); //nothing happen
    oe.treat(City::Miami); //miami = 0
    CHECK(board[City::Miami]==0);
    CHECK_THROWS(v.treat(City::SanFrancisco));
    v.take_card(City::SanFrancisco); // 1 blue 
    CHECK_THROWS(v.treat(City::Montreal)); //have just SanFransisco card, but no Montreal
    v.treat(City::SanFrancisco);  //SanFransisco =4
    CHECK(board[City::SanFrancisco]==4);
    r.take_card(City::StPetersburg).
    take_card(City::Paris).
    take_card(City::Essen).
    take_card(City::Madrid).
    take_card(City::Atlanta); // 5 blue cards
    r.discover_cure(Color::Blue); // Blue - V
    m.treat(City::Madrid); // Madrid = 0
    m.drive(City::NewYork); // the medic reset cubes automatically
    CHECK(board[City::NewYork]==0);
    d.drive(City::Tehran); 
    d.fly_direct(City::Sydney); //can fly to any city if he is at rsrch st
    d.take_card(City::Sydney);
    d.build(); //Sydney - V
    CHECK_THROWS(s.discover_cure(Color::Red)); //have no cards
    s.take_card(City::Osaka).take_card(City::Chennai);
    CHECK_THROWS(s.discover_cure(Color::Red)); //need one more red card(2 red cards to dicover)
    s.take_card(City::HoChiMinhCity);
    s.discover_cure(Color::Red); //Red - V
    d.treat(City::Sydney); //Sysney = 0
    CHECK(board[City::Sydney]==0);
    m.drive(City::Montreal); //curr_city= Montreal Montreal = 0
    CHECK(board[City::Montreal]==0);
    r.take_card(City::Delhi).
    take_card(City::Mumbai).
    take_card(City::Kolkata).
    take_card(City::Cairo).
    take_card(City::Mumbai); // 4 black
    CHECK_THROWS(r.discover_cure(Color::Black)); // 2 duplicate cards of mumbai
    r.take_card(City::Istanbul);// 5 Black 
    r.discover_cure(Color::Black); //Black - V
    oe.fly_shuttle(City::Tehran).treat(City::Tehran);//treat tehran. Tehran = 0
    oe.drive(City::Baghdad).treat(City::Baghdad); //Baghdad = 0
    CHECK_THROWS(fd.treat(City::Washington));//Washington is free 
    fd.treat(City::Atlanta); //Atlanta = 0
    fd.take_card(City::Washington);
    fd.fly_charter(City::London).treat(City::London); //London = 0
    CHECK_THROWS(fd.treat(City::SanFrancisco));//inaccessible
    CHECK(board[City::SanFrancisco]>0);
    CHECK_THROWS(fd.fly_direct(City::SanFrancisco));//no card of SanFrancisco
    fd.take_card(City::SanFrancisco);
    fd.fly_direct(City::SanFrancisco).treat(City::SanFrancisco); //SanFrancisco=0
    CHECK(board[City::SanFrancisco]==0);
    r.treat(City::HongKong); //HongKong=0
    oe.drive(City::Tehran).
    fly_direct(City::Miami).
    drive(City::MexicoCity).treat(City::MexicoCity); //Mexico = 0
    v.take_card(City::Khartoum);
    CHECK_THROWS(v.treat(City::Johannesburg));//need Johannesburg card
    v.take_card(City::Johannesburg).treat(City::Johannesburg); // Johannesburg = 0
    m.drive(City::Chicago); //Chicago = 0
    CHECK(board[City::Chicago]==0);
    CHECK(board.is_clean()==true);
    

    


  

}
