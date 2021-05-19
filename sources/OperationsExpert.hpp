#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"

namespace pandemic{
    class OperationsExpert : public Player {
        public:
            OperationsExpert(Board &board,City c);
            std::string role();
            OperationsExpert& build();


    };
}