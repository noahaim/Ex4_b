#pragma once
#include <string>
#include <map>
#include "City.hpp"
#include "Color.hpp"
namespace pandemic{
    class Board{
        std::map<City,int> numDiseases;
        std::set<City> station;
        std::set<Color> medication;
        static std::map< City, city_data>  mapCitis;
        public:
            Board();
            int& operator[](City c);
            int operator[](City c) const;
            friend std::ostream& operator<< (std::ostream& os, const Board& b);
            bool is_clean();
            void remove_cures();
            void remove_stations();
            static std::map<City,city_data> getMapCitis();
            std::map<City,int>& getNumDiseases();
            std::set<City>& getStation();
            std::set<Color>& getMedication();
            
    };
}