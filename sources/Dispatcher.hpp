#pragma once
#include "Player.hpp"


namespace pandemic{

    class Dispatcher: public Player {

        string name= "Dispatcher";

        public:
            Dispatcher(Board& board, City city) :Player(board,city){};
            Player& fly_direct(City city) override;
            string role()override{return name;};
           
    };

}