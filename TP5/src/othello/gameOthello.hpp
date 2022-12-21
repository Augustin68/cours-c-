#ifndef GAME_OTHELLO_CPP
#define GAME_OTHELLO_CPP

#include <iostream>

#include "../generic/game/gameStrategy.hpp"
#include "../generic/grid/gridGamePlacement.hpp"
#include "../shared/utils.hpp"

class GameOthello : public GameStrategy, public GridGamePlacement {
    public:
        GameOthello();
        virtual ~GameOthello() = default;
        Position placeToken(const char symbol) const override;
        bool checkWin(const Position lastPlayPos) const override;
        bool canPlaceToken(const int line, const int col, const char symbol) const;
    private:
        bool checkAdjacentEnemyToken(const int line, const int col, const char symbol) const;
        bool checkOtherTokenAligned(const int line, const int col, const char symbol) const;
};

#endif // GAME_OTHELLO_CPP