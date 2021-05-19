#include "Researcher.hpp"
using namespace pandemic;
const int five=5;
Player& Researcher::discover_cure(Color color) { 
        
        if(cards.size()<five){throw " less than 5 cards";}
        
        set<City> color_city_count;
        for (auto card : cards)
        {
            if (Board::get_color(card) == color)
            {
                
                color_city_count.insert(card);
            }
            if (color_city_count.size() == five)
            {
                break;
            }
        }
        
         if(color_city_count.size()<five){
            throw "there are not 5 cards of the same color";
        }
            for (auto x : color_city_count)
        {   
            cards.erase(x);
            
        }
        m_board.set_cure(color);
        
        
    return *this; };