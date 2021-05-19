#include "Player.hpp"
namespace pandemic{
    class Medic : public Player{
        public:
        Medic(Board &board,City c);
        std::string role();
        Medic& treat(City c);
        Medic& drive(City c);
        Medic& fly_direct(City c);
        Medic& fly_charter(City c);
        Medic& fly_shuttle(City c);
    };
}