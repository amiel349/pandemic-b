#include "Medic.hpp"
using namespace pandemic;

Player& Medic::treat(City city) {
    if(m_board[city]!=0){
        m_board[city]=0;
    }
    else{
        throw "the desease level is already 0";
    }
     return *this; };

void Medic::medic_treat()
{  
    if(m_board.is_there_cure(Board::get_color(m_city))){
    m_board[m_city]=0;
}

};