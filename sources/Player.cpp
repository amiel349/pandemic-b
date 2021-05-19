#include "Player.hpp"
#include <vector>
#include <set>
using namespace pandemic;
const int five=5;
static const map<City, set<City>> cities_list{
    {City::Algiers, {City::Madrid, City::Paris, City::Istanbul, City::Cairo}},
    {City::Atlanta, {City::Chicago, City::Miami, City::Washington}},
    {City::Baghdad, {City::Tehran, City::Istanbul, City::Cairo, City::Riyadh, City::Karachi}},
    {City::Bangkok, {City::Kolkata, City::Chennai, City::Jakarta, City::HoChiMinhCity, City::HongKong}},
    {City::Beijing, {City::Shanghai, City::Seoul}},
    {City::Bogota, {City::MexicoCity, City::Lima, City::Miami, City::SaoPaulo, City::BuenosAires}},
    {City::BuenosAires, {City::Bogota, City::SaoPaulo}},
    {City::Cairo, {City::Algiers, City::Istanbul, City::Baghdad, City::Khartoum, City::Riyadh}},
    {City::Chennai, {City::Mumbai, City::Delhi, City::Kolkata, City::Bangkok, City::Jakarta}},
    {City::Chicago, {City::SanFrancisco, City::LosAngeles, City::MexicoCity, City::Atlanta, City::Montreal}},
    {City::Delhi, {City::Tehran, City::Karachi, City::Mumbai, City::Chennai, City::Kolkata}},
    {City::Essen, {City::London, City::Paris, City::Milan, City::StPetersburg}},
    {City::HoChiMinhCity, {City::Jakarta, City::Bangkok, City::HongKong, City::Manila}},
    {City::HongKong, {City::Bangkok, City::Kolkata, City::HoChiMinhCity, City::Shanghai, City::Manila, City::Taipei}},
    {City::Istanbul, {City::Milan, City::Algiers, City::StPetersburg, City::Cairo, City::Baghdad, City::Moscow}},
    {City::Jakarta, {City::Chennai, City::Bangkok, City::HoChiMinhCity, City::Sydney}},
    {City::Johannesburg, {City::Kinshasa, City::Khartoum}},
    {City::Karachi, {City::Tehran, City::Baghdad, City::Riyadh, City::Mumbai, City::Delhi}},
    {City::Khartoum, {City::Cairo, City::Lagos, City::Kinshasa, City::Johannesburg}},
    {City::Kinshasa, {City::Lagos, City::Khartoum, City::Johannesburg}},
    {City::Kolkata, {City::Delhi, City::Chennai, City::Bangkok, City::HongKong}},
    {City::Lagos, {City::SaoPaulo, City::Khartoum, City::Kinshasa}},
    {City::Lima, {City::MexicoCity, City::Bogota, City::Santiago}},
    {City::London, {City::NewYork, City::Madrid, City::Essen, City::Paris}},
    {City::LosAngeles, {City::SanFrancisco, City::Chicago, City::MexicoCity, City::Sydney}},
    {City::Madrid, {City::London, City::NewYork, City::Paris, City::SaoPaulo, City::Algiers}},
    {City::Manila, {City::HongKong,::Taipei, City::SanFrancisco, City::HoChiMinhCity, City::Sydney}},
    {City::MexicoCity, {City::LosAngeles, City::Chicago, City::Miami, City::Lima, City::Bogota}},
    {City::Miami, {City::Atlanta, City::MexicoCity, City::Washington, City::Bogota}},
    {City::Milan, {City::Essen, City::Paris, City::Istanbul}},
    {City::Montreal, {City::Chicago, City::Washington, City::NewYork}},
    {City::Moscow, {City::StPetersburg, City::Istanbul, City::Tehran}},
    {City::Mumbai, {City::Karachi, City::Delhi, City::Chennai}},
    {City::NewYork, {City::Montreal, City::Washington, City::London, City::Madrid}},
    {City::Osaka, {City::Taipei, City::Tokyo}},
    {City::Paris, {City::Algiers, City::Essen, City::Madrid, City::Milan, City::London}},
    {City::Riyadh, {City::Baghdad, City::Cairo, City::Karachi}},
    {City::SanFrancisco, {City::LosAngeles, City::Chicago, City::Tokyo, City::Manila}},
    {City::Santiago, {City::Lima}},
    {City::SaoPaulo, {City::Bogota, City::BuenosAires, City::Lagos, City::Madrid}},
    {City::Seoul, {City::Beijing, City::Shanghai, City::Tokyo}},
    {City::Shanghai, {City::Beijing, City::HongKong, City::Taipei, City::Seoul, City::Tokyo}},
    {City::StPetersburg, {City::Essen, City::Istanbul, City::Moscow}},
    {City::Sydney, {City::Jakarta, City::Manila, City::LosAngeles}},
    {City::Taipei, {City::Shanghai, City::HongKong, City::Osaka, City::Manila}},
    {City::Tehran, {City::Baghdad, City::Moscow, City::Karachi, City::Delhi}},
    {City::Tokyo, {City::Seoul, City::Shanghai, City::Osaka, City::SanFrancisco}},
    {City::Washington, {City::Atlanta, City::NewYork, City::Montreal, City::Miami}}};

Player& Player::drive(City city)
{
    if(city==m_city){
    throw " can not drive from to it self city";
}

    if (is_connected(m_city, city))
    {
        m_city = city;
        medic_treat();
    }
    else
    {
        throw " cities are not connected";
    }
    return *this;
};

Player& Player::fly_direct(City city)
{
    if(city==m_city){
    throw " can not fly from to it self city";
}
    if (cards.contains(city))
    {
        cards.erase(city);
        m_city = city;
        medic_treat();
    }
    else
    {
        throw "you dont have the neccesary card";
    }
    return *this;
};
Player& Player::fly_charter(City city)
{
    if(city==m_city){
    throw " can not fly from to it self city";
}
     
    if (cards.contains(m_city))
    {
        cards.erase(m_city);
        m_city = city;
        medic_treat();
    }
    else
    {
        throw "you dont have the neccesary card";
    }
    return *this;
};

Player &Player::fly_shuttle(City city)
{
if(city==m_city){
    throw " can not fly from to it self city";
}

    if (m_board.fly_shuttle_research_stations(m_city, city))
    {
        m_city = city;
        medic_treat();
    }
    else
    {
        throw "there is not research station in both cities";
    }
    return *this;
};
Player& Player::build()
{
    if (cards.contains(m_city))
    {
       m_board.build_research(m_city);
        cards.erase(m_city);
    }
   
    else
    {
        throw " you dont have the nescecry card";
    }
    return *this;
};

Player& Player::discover_cure(Color color)
{   if(cards.size()<five){throw "less than 5 cards";}

    if (m_board.is_there_reserch(m_city))
    {
        if (m_board.is_there_cure(color))
        {
            return *this;
        }
        
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
        if(color_city_count.size()==five){
            for (auto x : color_city_count)
        { 
            cards.erase(x);
            
        }
        m_board.set_cure(color);
        }
        else{
            throw " there are not 5 cards of the same color";
        }
        
    }
    else
    {
        throw " there is not a research build in the current city";
    }
    return *this;
};

Player& Player::treat(City city)
{
     if (m_city != city) {
        throw "illegal- you are not in the correct city";
    }
    if (m_board[city] == 0)
    {
        throw "the deasese level in the city is already 0";
    }
    if(m_board.is_there_cure(Board::get_color(city))){
        m_board[city]=0;
    }
    else{
        m_board[city]-=1;
    }

    return *this;
};
Player& Player::take_card(City city)
{
    cards.insert(city);
    return *this;
};
string Player::role() { return name; };

bool Player::is_connected(City city, City other)
{

    return cities_list.at(city).contains(other);
};
void Player::remove_cards()
{
    cards.clear();
};

void Player::medic_treat()
{
};

