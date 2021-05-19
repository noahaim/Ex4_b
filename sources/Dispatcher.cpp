#include "Dispatcher.hpp"
namespace pandemic{
    Dispatcher::Dispatcher(Board &board,City c):Player(board,c){}
    std::string Dispatcher::role(){
        return "Dispatcher";
    }
    Dispatcher& Dispatcher::fly_direct(City c){
        if(c==hisCity){
            throw std::invalid_argument("can not fly to himself");}
        if(board.getStation().find(hisCity)!=board.getStation().end())
        {
            hisCity=c;
        }
        else {Player::fly_direct(c);}
        return *this;
    }

}