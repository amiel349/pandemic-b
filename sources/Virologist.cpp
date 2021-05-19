#include "Virologist.hpp"
#include "Board.hpp"
using namespace pandemic;

Player& Virologist::treat(City city) { 
     if(m_board[city]==0){
        throw " illegal: the desease level in the city is allready 0";
    }
    if(city==m_city){
        m_board[m_city]--;
        return *this;
    }
    if(!cards.contains(city)){
        throw "you dont have the relevant card";
    }
    cards.erase(city);
    if(m_board.is_there_cure(Board::get_color(city))){
        m_board[city]=0;
    }
    else{
        m_board[city]--;
    }
    return *this; };