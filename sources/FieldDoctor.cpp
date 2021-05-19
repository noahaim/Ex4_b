#include "FieldDoctor.hpp"
namespace pandemic{
    FieldDoctor::FieldDoctor(Board &board, City c):Player(board,c){}
    std::string FieldDoctor::role(){
        return "FieldDoctor";
    }
    FieldDoctor& FieldDoctor::treat(City c)
    {
        // if(board.getNumDiseases().at(c)==0)
            // throw std::invalid_argument("no diseases in c city");
        if(board[c]==0){
            throw std::invalid_argument("no diseases in this city");}
        if(pandemic::Board::getMapCitis().at(hisCity).neighbors.count(c)!=0||c==hisCity)
        {
            if(board.getMedication().count(pandemic::Board::getMapCitis().at(c).color)!=0){//there is medication to this color city
                board[c]=0;}
            else {board[c]--;}
        }
        else{  throw std::invalid_argument(" not neighbors ");}

        return *this;
    }
    
}