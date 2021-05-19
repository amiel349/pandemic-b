#include "FieldDoctor.hpp"
using namespace pandemic;

Player &FieldDoctor::treat(City city) {
    if(m_board[city]==0){
        throw " illegal: the desease level in the city is allready 0";
    }
     if(city==m_city){
        m_board[m_city]--;
        return *this;
    }
    if(is_connected(m_city,city))
    {m_board[city]--;}
    else{throw "the cities are not connected- can not make treat";} return *this; };