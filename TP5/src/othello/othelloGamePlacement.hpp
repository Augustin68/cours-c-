#ifndef OTHELLO_GAME_PLACEMENT
#define OTHELLO_GAME_PLACEMENT

#include "../generic/game/gameStrategy.hpp"

class OthelloGamePlacement {
    protected:
        virtual bool canPlaceToken(const int line, const int column, const char symbol) const = 0;
};

#endif // OTHELLO_GAME_PLACEMENT