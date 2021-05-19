#include "OperationsExpert.hpp"
using namespace pandemic;

Player& OperationsExpert::build(){
    m_board.build_research(m_city);
    return *this;};