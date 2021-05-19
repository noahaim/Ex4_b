#include "Player.hpp"
namespace pandemic{
    class Virologist : public Player{
        public:
        Virologist(Board &board,City c);
        std::string role();
        Virologist& treat(City c);
    };
}