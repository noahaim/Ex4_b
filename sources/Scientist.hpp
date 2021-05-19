#include "Player.hpp"
namespace pandemic{
    class Scientist : public Player{
        int number;
        public:
        Scientist(Board &board, City c,int n);
        std::string role();
        bool discover_cure(Color c);


    };
}