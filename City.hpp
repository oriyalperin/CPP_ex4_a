#pragma once
#include <ostream>
#include <unordered_set>
#include "Color.hpp"
using namespace std;
static const int size_city=48;

enum class City{

Algiers,
Atlanta,
Baghdad,
Bangkok,
Beijing,
Bogota,
BuenosAires,
Cairo,
Chennai,
Chicago,
Delhi,
Essen,
HoChiMinhCity,
HongKong,
Istanbul,
Jakarta,
Johannesburg,
Karachi,
Khartoum,
Kinshasa,
Kolkata,
Lagos,
Lima,
London,
LosAngeles,
Madrid,
Manila,
MexicoCity,
Miami,
Milan,
Montreal,
Moscow,
Mumbai,
NewYork,
Osaka,
Paris,
Riyadh,
SanFrancisco,
Santiago,
SaoPaulo,
Seoul,
Shanghai,
StPetersburg,
Sydney,
Taipei,
Tehran,
Tokyo,
Washington

};

typedef class city_dtls
{
    public:
    string name;
    Color color;
    int cubes;
    bool rsrch_st;   
    unordered_set<City> nbrs;
    city_dtls(string name, Color color,unordered_set <City> nbrs) : 
    name(name), color(color), cubes(0),rsrch_st(false), nbrs(nbrs) {};
}city_dtls;



