#include "Researcher.hpp"
const int  AMOUNT_CARDS_DISCOVER =5;
namespace pandemic{
    Researcher::Researcher(Board &board, City c):Player(board,c){}
    std::string Researcher::role(){
        return "Researcher";
    }
    bool Researcher::discover_cure(Color c){
         if(board.getMedication().find(c)==board.getMedication().end())
        {
            int counter=0;
            std::set<City> cardToRemove;
            for (const auto &card : cards)
             {
	            if (pandemic::Board::getMapCitis().at(card).color==c)
                    {
                        if(counter==AMOUNT_CARDS_DISCOVER){
                            break;}
                        cardToRemove.insert(card);
                        counter++;
                        }
                }
            
            if (counter<AMOUNT_CARDS_DISCOVER){
                throw std::invalid_argument("not have 5 cards with the same color of the diseases");
            }
            for (const auto& card : cardToRemove){
               cards.erase(card); }
            board.getMedication().insert(c);
            return true;
        }
        return false;
    }
    

}