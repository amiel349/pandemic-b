#include "Board.hpp"
#include <map>
#include <vector>
using namespace std;
using namespace pandemic;



namespace pandemic
{

     
    // constructor
    Board::Board(){};
    int& Board::operator[](pandemic::City city)
    {
        return diseases_map[city];
    }
    void Board::remove_cures(){
        cure_map.clear();
    };
    ostream& operator<<(ostream& os, pandemic::Board& board) { return os; };

    bool Board::is_clean() { 
        
         for(auto& [key,value] : diseases_map){
            if(value>0){
            return false;}
        }
        
        return true; };

    bool Board::fly_shuttle_research_stations(City city, City other){
        
        return (research_stations_map[city]&&research_stations_map[other]);
    }

    void Board:: build_research(City city){
        
        research_stations_map[city]=true;;
    }
    
     bool Board::is_there_reserch(City city){
        return research_stations_map[city];
    }

    bool Board::is_there_cure(Color color){
        return cure_map[color];
    }

    void Board::set_cure(Color color){
        cure_map[color]=true;
    }

    
}