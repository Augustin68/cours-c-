#ifndef GAME_OTHELLO_CPP
#define GAME_OTHELLO_CPP

#include <iostream>

#include "../generic/game/gameStrategy.hpp"
#include "./othelloGamePlacement.hpp"
#include "../shared/utils.hpp"

class GameOthello : public GameStrategy, public OthelloGamePlacement {
    public:
        GameOthello();
        virtual ~GameOthello() = default;
        Position placeToken(const char token) const override;
        bool checkWin(const Position lastPlayPos) const override;
        bool canPlaceToken(const int line, const int column, const char token) const;
    private:
        bool checkAdjacentEnemyToken(const int line, const int column, const char token) const;
        void flipTokens(const Position pos, const char token) const;
};

#endif // GAME_OTHELLO_CPP