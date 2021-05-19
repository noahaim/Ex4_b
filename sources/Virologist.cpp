#include "Virologist.hpp"
namespace pandemic{
    Virologist::Virologist(Board &board,City c):Player(board,c){}
    std::string Virologist::role()
    {
        return "Virologist";
    }
    Virologist& Virologist::treat(City c)
    { 
        if(c==hisCity){
            Player::treat(c);
            return *this;
        }
         if(board[c]==0){
               throw std::invalid_argument("no diseases in this city");}
        if(cards.count(c)!=0)//she have the card to the city
        {
            if(board.getMedication().count(pandemic::Board::getMapCitis().at(c).color)!=0)//there is medication to this color city
            {
                board[c]=0;
            }
            else{board[c]--;}
        }
        else {throw std::invalid_argument("not have the card of the city she want to treat");}
         return *this;
    }
}