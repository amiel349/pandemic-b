#pragma once
//#include "City.hpp"
//#include "Color.hpp"
#include "Player.hpp"
//#include "Board.hpp"

namespace pandemic{

    class Researcher: public Player {

        string name="Researcher";

        public:
            Researcher(Board& board, City color): Player(board, color) {};
            Player& discover_cure(Color color) override;
            string role()override{return name;};
            
    };

}