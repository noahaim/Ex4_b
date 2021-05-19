#include "Player.hpp"
#include <iostream>
const int  AMOUNT_CARDS_DISCOVER =5;
namespace pandemic{
            
            Player::Player(Board &b,City c):board(b),hisCity(c){

            }
            Player& Player::drive(City c){
                if(c==hisCity){
                    throw std::invalid_argument("can not drive to himself");}
                if(pandemic::Board::getMapCitis().at(hisCity).neighbors.count(c)==0){
                    throw std::invalid_argument ("cant move to distance city");}
                hisCity=c;
                return *this;
            }
            Player& Player::fly_direct(City c){
                if(c==hisCity){
                    throw std::invalid_argument("can not fly to himself");}
                if(cards.find(c)!=cards.end())
                {
                    hisCity=c;
                    cards.erase(c);
                }
                else{ throw std::invalid_argument("not have the card of this city");}
                return *this;
            }
            Player& Player::fly_charter(City c){
                if(c==hisCity){
                    throw std::invalid_argument("can not fly to himself");}
                if(cards.find(hisCity)==cards.end()){
                    throw std::invalid_argument("not have the card of this city");}
                cards.erase(hisCity);
                hisCity=c;
                return *this;
            }
            Player& Player::fly_shuttle(City c){
                if(c==hisCity){
                    throw std::invalid_argument("can not fly to himself");}
                if(board.getStation().count(c)==0){
                    throw std::invalid_argument("not have station in the city he want to go");}
                if(board.getStation().find(hisCity)==board.getStation().end()){
                    throw std::invalid_argument("not have station in his city");}
                hisCity=c;
                return *this;
            }
            Player& Player::build(){
                if(cards.find(hisCity)!=cards.end())//check that he have the card of his city
                {
                    if(board.getStation().find(hisCity)==board.getStation().end()){//check there is no station is gis city
                         board.getStation().insert(hisCity);
                         cards.erase(hisCity);
                    }
                }
                else {throw std::invalid_argument("not have the card of his city");}
                return *this;
            }
            bool Player::discover_cure(Color c){
                if(board.getStation().find(hisCity)!=board.getStation().end())
                {
                    if(board.getMedication().find(c)==board.getMedication().end()){
                    int counter=0;
                    std::set<City> cardToRemove;
                    for (const auto& card : cards) {
		                if (pandemic::Board::getMapCitis().at(card).color==c)
                            {
                                if(counter==AMOUNT_CARDS_DISCOVER){
                                    break;}
                                cardToRemove.insert(card);
                                counter++;
                            }
                    }
                    if (counter<AMOUNT_CARDS_DISCOVER){
                        throw std::invalid_argument("not have 5 cards with the same color of the diseases");}
                    for (const auto& card : cardToRemove){
                        cards.erase(card); }
                    board.getMedication().insert(c);
                    return true;
                    }
                }
                else {throw std::invalid_argument("not have station in this city");}
                return false;
            }
            Player& Player::treat(City c){
                if(board[c]==0){
                    throw std::invalid_argument("no diseases in this city");}
                // if(board.getNumDiseases().find(hisCity)==board.getNumDiseases().end())
                //      throw std::invalid_argument("no diseases in this city");
                if(board.getMedication().count(pandemic::Board::getMapCitis().at(hisCity).color)!=0)//there is medication to this color city
                {
                    board[hisCity]=0;
                }
                else{ board[hisCity]--;}
                return *this;
            }
            // std::string Player::role();

            Player& Player::take_card(City c){
                if(cards.count(c)==0)//this player dont have this card 
                    {
                        cards.insert(c);
                    }
                return *this;
            }
            void Player::remove_cards(){
                cards.clear();
            }

}