#include "GeneSplicer.hpp"
using namespace pandemic;
const int five=5;

Player &GeneSplicer::discover_cure(Color color) {

    if(!m_board.is_there_reserch(m_city)){throw " there is no research station";}
    if(cards.size()<five){throw " less than 5 cards";}
    size_t i=0;
    array<City,five>city_to_erase{};
    for(auto card : cards){
        if(i==five){break;}
        city_to_erase.at(i)=card;
        i++;
    }
    for (size_t i = 0; i < five; i++)
    {
        cards.erase(city_to_erase.at(i));
    }
    m_board.set_cure(color); 
    
    return *this;
     };