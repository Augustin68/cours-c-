#ifndef GAME_TICTACTOE_HPP
#define GAME_TICTACTOE_HPP

#include <iostream>

#include "../generic/game/gameStrategy.hpp"
#include "../generic/grid/gridGamePlacement.hpp"

class GameTicTacToe : public GameStrategy, public GridGamePlacement {
    public:
        GameTicTacToe();
        virtual ~GameTicTacToe() = default;
        Position placeToken(char symbol) const override;
        bool checkWin(Position lastPlayPos) const override;
        bool canPlaceToken(int line, int col) const override;
};

#endif //GAME_TICTACTOE_HPP