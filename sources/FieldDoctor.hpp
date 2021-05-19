#include "Player.hpp"
namespace pandemic{
    class FieldDoctor : public Player{
        public:
        FieldDoctor(Board &board, City c);
        std::string role();
        FieldDoctor& treat(City c);
    };
}