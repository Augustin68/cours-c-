#ifndef GAME_TICTACTOE_HPP
#define GAME_TICTACTOE_HPP

#include <iostream>

#include "gameStrategy.hpp"

class GameTicTacToe : public GameStrategy {
    public:
        GameTicTacToe();
        ~GameTicTacToe();
        void placeToken() const override {
            std::cout << "Placing token as TIC TAC TOE" << std::endl; 
        };
        void checkWin() const override {

        };
};

#endif //GAME_TICTACTOE_HPP