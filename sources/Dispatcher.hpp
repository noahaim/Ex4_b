#include "Player.hpp"
namespace pandemic{
    class Dispatcher : public Player{
        public:
        Dispatcher(Board &board,City c);
        std::string role();
        Dispatcher& fly_direct(City c);

    };
}