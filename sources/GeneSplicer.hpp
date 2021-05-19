#pragma once
#include "Player.hpp"

namespace pandemic{

    class GeneSplicer: public Player {

        string name="GeneSplicer";

        public:
            GeneSplicer(Board& board, City city): Player(board, city) {};
            Player& discover_cure(Color color) override;
            string role()override{return name;};
           
    };
    
}