#pragma once
//#include "City.hpp"
//#include "Color.hpp"
#include "Player.hpp"
//#include "Board.hpp"

namespace pandemic{

    class Medic: public Player {

        string name="Medic";

        public:
            Medic(Board& board, City city): Player(board, city) {};
            Player& treat(City city) override;
            void medic_treat()override;
            string role()override{return name;};
       
    };
}