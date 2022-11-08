#ifndef GAME_CONNECTFOUR_HPP
#define GAME_CONNECTFOUR_HPP

#include <iostream>

#include "gameStrategy.hpp"

class GameConnectFour : public GameStrategy {
    public:
        GameConnectFour();
        ~GameConnectFour() { };
        void placeToken(char symbol) const override {
            std::cout << "Placing token as Connect four !" << std::endl; 
        };
        void checkWin() const override {

        };
};

#endif //GAME_CONNECTFOUR_HPP