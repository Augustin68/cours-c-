#ifndef GRID_GAME_PLACEMENT
#define GRID_GAME_PLACEMENT

#include "../game/gameStrategy.hpp"

class GridGamePlacement {
    protected:
        virtual bool canPlaceToken(const int line, const int column) const = 0;
};

#endif // GRID_GAME_PLACEMENT