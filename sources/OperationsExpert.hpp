#pragma once
#include "Player.hpp"

namespace pandemic{

    class OperationsExpert: public Player {

        string name ="OperationsExpert";

        public:
            OperationsExpert(Board& board, City city): Player(board,city){};
            Player& build() override;
            string role()override{return name;};
          
    };

}