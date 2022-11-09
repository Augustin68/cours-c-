#ifndef GAME_TICTACTOE_HPP
#define GAME_TICTACTOE_HPP

#include <iostream>

#include "gameStrategy.hpp"

class GameTicTacToe : public GameStrategy {
    public:
        GameTicTacToe();
        ~GameTicTacToe();
        Position placeToken(char symbol) const override;
        bool checkWin(Position lastPlayPos) const override;
        bool canPlaceToken(int line, int col) const override;
};

#endif //GAME_TICTACTOE_HPP