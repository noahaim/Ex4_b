#include "Medic.hpp"
namespace pandemic{
     Medic::Medic(Board &board,City c):Player(board,c){}
     std::string Medic::role()
     {
          return "Medic";
     }
     Medic& Medic::treat(City c)
     {
          // if(board.getNumDiseases().find(hisCity)!=board.getNumDiseases().end()&&board.getNumDiseases().at(hisCity)==0)
          //      throw std::invalid_argument("no diseases in this city");
          //  if(board.getNumDiseases().find(hisCity)==board.getNumDiseases().end())
          if(board[c]==0){
               throw std::invalid_argument("no diseases in this city");}
          board[hisCity]=0;
          return *this;
     }
     Medic& Medic::drive(City c)
     {
          if(board.getMedication().find(pandemic::Board::getMapCitis().at(c).color)!=board.getMedication().end()){
               board[c]=0;}
          Player::drive(c);
          return *this;
     }
     Medic& Medic::fly_direct(City c)
     {
          if((board.getMedication().count(pandemic::Board::getMapCitis().at(c).color))!=0){
               board[c]=0;}
          Player::fly_direct(c);
          return *this;
     }
     Medic& Medic::fly_charter(City c)
     {
          if(board.getMedication().count(pandemic::Board::getMapCitis().at(c).color)!=0){
               board[c]=0;}
          Player::fly_charter(c);
          return *this;
     }
     Medic& Medic::fly_shuttle(City c)
     {
           if(board.getMedication().find(pandemic::Board::getMapCitis().at(c).color)!=board.getMedication().end()){
               board[c]=0;}
          Player::fly_shuttle(c);
          return *this;
     }
}