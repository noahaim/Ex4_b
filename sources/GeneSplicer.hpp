#include "Player.hpp"
namespace pandemic{
    class GeneSplicer : public Player{
        public:
        GeneSplicer(Board &board, City c);
        std::string role();
        bool discover_cure(Color c);

    };
}
