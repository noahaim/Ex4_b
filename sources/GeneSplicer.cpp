#include "GeneSplicer.hpp"
const int  AMOUNT_CARDS_DISCOVER =5;
namespace pandemic{
    GeneSplicer::GeneSplicer(Board &board, City c):Player(board,c){}
    std::string GeneSplicer::role(){
        return "GeneSplicer";
    }
    bool GeneSplicer::discover_cure(Color c)
    {
        if(cards.size()<AMOUNT_CARDS_DISCOVER){
            throw std::invalid_argument("not have 5 cards");
        }
        if(board.getStation().find(hisCity)!=board.getStation().end())
        {
            if(board.getMedication().find(c)==board.getMedication().end()){
                int counter=0;
                std::set<City> cardToRemove;
                for (const auto& card : cards){
                    if(counter==AMOUNT_CARDS_DISCOVER){
                        break;}
                    cardToRemove.insert(card);
                    counter++;
                }
                for (const auto& card : cardToRemove){
                   cards.erase(card); }
                board.getMedication().insert(c);
                return true;
            }
        }
        else {throw std::invalid_argument("not have station in his city");}
        return false;
     }
    

}