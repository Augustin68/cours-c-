#ifndef GRIDGAMESTRATEGY_HPP
#define GRIDGAMESTRATEGY_HPP

#include "../game/gameStrategy.hpp"

class GridGamePlacement {
    protected:
        virtual bool canPlaceToken(int line, int col) const = 0;
};

#endif // GRIDGAMESTRATEGY_HPP