#include "Dispatcher.hpp"

pandemic::Player &pandemic::Dispatcher::fly_direct(City city) {

    if(city==m_city){
    throw " can not fly from to it self city";
}
    if(m_board.is_there_reserch(m_city)){
        m_city=city;
        return *this;
    }
    if(cards.contains(city)){
        m_city=city;
        cards.erase(city);
    }
    else{
        throw " there is no resaerch station in this city and you dont have the destination card";
    }

    
     return *this; };
