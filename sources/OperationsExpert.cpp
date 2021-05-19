#include "OperationsExpert.hpp"
namespace pandemic{
    OperationsExpert::OperationsExpert(Board & board,City c):Player(board,c){}
    std::string OperationsExpert::role(){
        return "OperationsExpert";
    }
    OperationsExpert& OperationsExpert::build(){
        if(board.getStation().find(hisCity)==board.getStation().end())
            {
                board.getStation().insert(hisCity);
            }
        return *this;
    }

}
