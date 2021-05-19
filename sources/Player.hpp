#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <set>
namespace pandemic{
    class Player{
        protected:
            std::set<City> cards;
            City hisCity;
            Board &board;
        public:
            Player(Board& board,City c);
            virtual Player& drive(City c);
            virtual Player& fly_direct(City c);
            virtual Player& fly_charter(City c);
            virtual Player& fly_shuttle(City c);
            virtual Player& build();
            virtual bool discover_cure(Color c);
            virtual Player& treat(City c);
            virtual std::string role()=0;
            Player& take_card(City c);
            void remove_cards();

    };
}