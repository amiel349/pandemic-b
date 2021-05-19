#pragma once
#include <map>
#include <iostream>
#include "City.hpp"
#include "Color.hpp"
using namespace std;

namespace pandemic
{
    class Board
    {

    private:
     map<City, int> diseases_map;
      map<Color,bool> cure_map;
      map<City,bool> research_stations_map;
    
    public:
        // constructor
        Board();
        int& operator[](City city);
        void remove_cures();
        friend ostream& operator<<(ostream& os,Board& board);
        bool is_clean();
        bool fly_shuttle_research_stations(City city, City other);
        void  build_research(City city);
        bool is_there_reserch(City city);
        bool is_there_cure(Color color);
        void set_cure(Color color);
        static Color get_color(City city){return cities_colors_list.at(city);}
        
    };
}