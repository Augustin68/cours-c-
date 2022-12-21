#ifndef GAME_TICTACTOE_HPP
#define GAME_TICTACTOE_HPP

#include <iostream>

#include "../generic/game/gameStrategy.hpp"
#include "../generic/gamePlacement/gridGamePlacement.hpp"
#include "../shared/utils.hpp"

class GameTicTacToe : public GameStrategy, public GridGamePlacement {
    public:
        GameTicTacToe();
        virtual ~GameTicTacToe() = default;
        Position placeToken(const char token) const override;
        bool checkWin(const Position lastPlayPos) const override;
        bool canPlaceToken(const int line, const int column) const override;
};

#endif //GAME_TICTACTOE_HPP