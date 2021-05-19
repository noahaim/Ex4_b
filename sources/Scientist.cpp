#include "Scientist.hpp"
namespace pandemic{
    Scientist::Scientist(Board &board, City c,int n):Player(board,c),number(n){}
        std::string Scientist::role(){
            return "Scientist";
        }
        bool Scientist::discover_cure(Color c)
        {
            if(board.getStation().find(hisCity)!=board.getStation().end())
            {
                if(board.getMedication().count(c)==0){
                int counter=0;
                std::set<City> cardToRemove;
                for (const auto & card : cards) {
                    if (pandemic::Board::getMapCitis().at(card).color==c)
                        {
                            if(counter==number){
                                break;}
                            cardToRemove.insert(card);
                            counter++;
                        }
                }
                if (counter<number)
                {
                    throw std::invalid_argument("not have enough cards with the same color of the diseases");
                }
                for (const auto& card : cardToRemove){
                    cards.erase(card); }
                board.getMedication().insert(c);
                return true;
            }
            }
            else{ throw std::invalid_argument("not have station in his city");}
            return false;
        }
}
