#pragma once
#include "Player.hpp"

namespace pandemic{

    class FieldDoctor: public Player {

        string name="FieldDoctor";

        public:
            FieldDoctor(Board& board, City city): Player(board, city) {};
            Player& treat(City city) override;
            string role()override{return name;};
           
    };

}