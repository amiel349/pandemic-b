#pragma once
#include "Board.hpp"
#include <set>
using namespace std;

namespace pandemic
{
    class Player
    {

    protected:
        pandemic::Board& m_board;
        pandemic::City m_city;
        set<City> cards;
        const string name="Player";

    public:
        Player(pandemic::Board &board, pandemic::City city): m_board(board), m_city(city){}
        Player& drive(pandemic::City city);
        virtual Player& fly_direct(pandemic::City city);
        Player& fly_charter(pandemic::City city);
        Player& fly_shuttle(pandemic::City city);
        virtual Player& build();
        virtual Player& discover_cure(pandemic::Color color);
        virtual Player& treat(pandemic::City city);
        Player& take_card(pandemic::City city);
        virtual string role();
        static bool is_connected(City city, City other);
        void remove_cards();
        virtual void medic_treat();
    };

}