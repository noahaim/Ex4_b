#include "Board.hpp"
using namespace pandemic;
using namespace std;
std::map< City,  city_data>  Board::mapCitis;

namespace pandemic{
    Board::Board(){
    mapCitis={
        {City::Algiers,(city_data){Color::Black,{City::Madrid, City::Paris, City::Istanbul, City::Cairo}}},
        {City::Atlanta,(city_data){Color::Blue,{City::Chicago, City::Miami, City::Washington}}},
        {City::Baghdad,(city_data){Color::Black,{City::Tehran, City::Istanbul, City::Cairo, City::Riyadh, City::Karachi}}},
        {City::Bangkok,(city_data){Color::Red,{City::Kolkata, City::Chennai, City::Jakarta, City::HoChiMinhCity, City::HongKong}}},
        {City::Beijing,(city_data){Color::Red,{City::Shanghai, City::Seoul}}},
        {City::Bogota,(city_data){Color::Yellow,{City::MexicoCity, City::Lima, City::Miami, City::SaoPaulo, City::BuenosAires}}},
        {City::BuenosAires,(city_data){Color::Yellow,{City::Bogota, City::SaoPaulo}}},
        {City::Cairo,(city_data){Color::Black,{City::Algiers, City::Istanbul, City::Baghdad, City::Khartoum, City::Riyadh}}},
        {City::Chennai,(city_data){Color::Black,{City::Mumbai, City::Delhi, City::Kolkata, City::Bangkok, City::Jakarta}}},
        {City::Chicago,(city_data){Color::Blue,{City::SanFrancisco, City::LosAngeles, City::MexicoCity, City::Atlanta, City::Montreal}}},
        {City::Delhi,(city_data){Color::Black,{City::Tehran, City::Karachi, City::Mumbai, City::Chennai, City::Kolkata}}},
        {City::Essen,(city_data){Color::Blue,{City::London, City::Paris, City::Milan, City::StPetersburg}}},
        {City::HoChiMinhCity,(city_data){Color::Red,{City::Jakarta, City::Bangkok, City::HongKong, City::Manila}}},
        {City::HongKong,(city_data){Color::Red,{City::Bangkok, City::Kolkata, City::HoChiMinhCity, City::Shanghai, City::Manila, City::Taipei}}},
        {City::Istanbul,(city_data){Color::Black,{City::Milan, City::Algiers, City::StPetersburg, City::Cairo, City::Baghdad, City::Moscow}}},
        {City::Jakarta,(city_data){Color::Red,{City::Chennai, City::Bangkok, City::HoChiMinhCity, City::Sydney}}},
        {City::Johannesburg,(city_data){Color::Yellow,{City::Kinshasa, City::Khartoum}}},
        {City::Karachi,(city_data){Color::Black,{City::Tehran, City::Baghdad, City::Riyadh, City::Mumbai, City::Delhi}}},
        {City::Khartoum,(city_data){Color::Yellow,{City::Cairo, City::Lagos, City::Kinshasa, City::Johannesburg}}},
        {City::Kinshasa,(city_data){Color::Yellow,{City::Lagos, City::Khartoum, City::Johannesburg}}},
        {City::Kolkata,(city_data){Color::Black,{City::Delhi, City::Chennai, City::Bangkok, City::HongKong}}},
        {City::Lagos,(city_data){Color::Yellow,{City::SaoPaulo, City::Khartoum, City::Kinshasa}}},
        {City::Lima,(city_data){Color::Yellow,{City::MexicoCity, City::Bogota, City::Santiago}}},
        {City::London,(city_data){Color::Blue,{City::NewYork, City::Madrid, City::Essen, City::Paris}}},
        {City::LosAngeles,(city_data){Color::Yellow,{City::SanFrancisco, City::Chicago, City::MexicoCity, City::Sydney}}},
        {City::Madrid,(city_data){Color::Blue,{City::London, City::NewYork, City::Paris, City::SaoPaulo, City::Algiers}}},
        {City::Manila,(city_data){Color::Red,{City::HongKong, City::Taipei, City::SanFrancisco, City::HoChiMinhCity, City::Sydney}}},
        {City::MexicoCity,(city_data){Color::Yellow,{City::LosAngeles, City::Chicago, City::Miami, City::Lima, City::Bogota}}},
        {City::Miami,(city_data){Color::Yellow,{City::Atlanta, City::MexicoCity, City::Washington, City::Bogota}}},
        {City::Milan,(city_data){Color::Blue,{City::Essen, City::Paris, City::Istanbul}}},
        {City::Montreal,(city_data){Color::Blue,{City::Chicago, City::Washington, City::NewYork}}},
        {City::Moscow,(city_data){Color::Black,{City::StPetersburg, City::Istanbul, City::Tehran}}},
        {City::Mumbai,(city_data){Color::Black,{City::Karachi, City::Delhi, City::Chennai}}},
        {City::NewYork,(city_data){Color::Blue,{City::Montreal, City::Washington, City::London, City::Madrid}}},
        {City::Osaka,(city_data){Color::Red,{City::Taipei, City::Tokyo}}},
        {City::Paris,(city_data){Color::Blue,{City::Algiers, City::Essen, City::Madrid, City::Milan, City::London}}},
        {City::Riyadh,(city_data){Color::Black,{City::Baghdad, City::Cairo, City::Karachi}}},
        {City::SanFrancisco,(city_data){Color::Blue,{City::LosAngeles, City::Chicago, City::Tokyo, City::Manila}}},
        {City::Santiago,(city_data){Color::Yellow,{City::Lima}}},
        {City::SaoPaulo,(city_data){Color::Yellow,{City::Bogota, City::BuenosAires, City::Lagos, City::Madrid}}},
        {City::Seoul,(city_data){Color::Red,{City::Beijing, City::Shanghai, City::Tokyo}}},
        {City::Shanghai,(city_data){Color::Red,{City::Beijing, City::HongKong, City::Taipei, City::Seoul, City::Tokyo}}},
        {City::StPetersburg,(city_data){Color::Blue,{City::Essen, City::Istanbul, City::Moscow}}},
        {City::Sydney,(city_data){Color::Red,{City::Jakarta, City::Manila, City::LosAngeles}}},
        {City::Taipei,(city_data){Color::Red,{City::Shanghai, City::HongKong, City::Osaka, City::Manila}}},
        {City::Tehran,(city_data){Color::Black,{City::Baghdad, City::Moscow, City::Karachi, City::Delhi}}},
        {City::Tokyo,(city_data){Color::Red,{City::Seoul, City::Shanghai, City::Osaka, City::SanFrancisco}}},
		{City::Washington,(city_data){Color::Blue,{City::Atlanta, City::NewYork, City::Montreal, City::Miami}}}
	    };
        for(const auto& c:mapCitis)
        {
            numDiseases.insert(std::pair<City,int>(c.first,0));
        }
    }
       int& Board::operator[](City c){
           return numDiseases.at(c);   
       }
       int Board::operator[](City c) const{
           return numDiseases.at(c);
       }
       std::ostream& operator<< (std::ostream& os, const Board& b){
           return os;
       } 
       bool Board::is_clean()
       {
           for(const auto & temp:numDiseases) 
           {
               if(temp.second!=0){
                    return false;}
           }
            return true;
       }
       void Board::remove_cures(){
           medication.clear();
       }
       void Board::remove_stations(){
           station.clear();
       }
       map< City,  city_data> Board::getMapCitis()
       {
           return mapCitis;
       }
       map<City,int>& Board::getNumDiseases()
       {
           return numDiseases;
       }
       set<City>& Board::getStation(){
           return station;
       }
       set<Color>& Board::getMedication()
       {
           return medication;
       }
}