#ifndef GAME_CONNECTFOUR_HPP
#define GAME_CONNECTFOUR_HPP

#include <iostream>

#include "gameStrategy.hpp"

class GameConnectFour : public GameStrategy {
    public:
        GameConnectFour();
        ~GameConnectFour() { };
        Position placeToken(char symbol) const override;
        bool checkWin(Position lastPlayPos) const override;
        bool canPlaceToken(int line, int col) const override;

};

#endif //GAME_CONNECTFOUR_HPP