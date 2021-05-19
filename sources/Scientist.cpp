#include "Scientist.hpp"
#include <string>
using namespace pandemic;

Player& Scientist::discover_cure(Color color) { 
    if (m_board.is_there_reserch(m_city))
    {
        // if (m_board.is_there_cure(color))
        // {  //throw " there is already a cure for this color";
        //     return *this;
        // }
        if(num==0){
            m_board.set_cure(color);
            return *this;

        }
        int count = 0;
        set<City> color_city_count;
        for (auto card : cards)
        {
            if (Board::get_color(card) == color)
            {
                count++;
                color_city_count.insert(card);
            }
            if (count == num)
            {
                break;
            }
        }
        
        if(count==num){
            for (auto x : color_city_count)
        {
            cards.erase(x);
        }
        m_board.set_cure(color);
        }
        else{
            throw " there are not n cards of the same color";
        }
        
    }
    else
    {
        throw " there is not a research build in the current city";
    }
    return *this; };
