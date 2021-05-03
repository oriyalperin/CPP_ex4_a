#pragma once
#include <ostream>
#include <string>
#include <map>
#include <list>
#include <fstream>
#include "City.hpp"
#include "Color.hpp"
#include <unordered_map>


 namespace pandemic
 {
    
    class Board
    {        
        private:
            
            void read_cities(std::ifstream& cities_file);
            std::string convert_disease(Color color);
        public:
            std::unordered_map<City,city_dtls> cities;
            std::map<Color,bool> diseases;
            Board();
            int& operator[](City city);
            friend std::ostream& operator<< (std::ostream& os, const Board& board);
            bool is_clean();
            void remove_cures();
            void remove_stations();
            string& get_city_name(City city);
    };

   


 }