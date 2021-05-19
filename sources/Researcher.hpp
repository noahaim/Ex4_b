#include "Player.hpp"
namespace pandemic{
    class Researcher : public Player{
        public:
        Researcher(Board &board, City c);
        std::string role();
        bool discover_cure(Color c);

    };
}