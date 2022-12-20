#ifndef GRIDGAMESTRATEGY_HPP
#define GRIDGAMESTRATEGY_HPP

#include "../game/gameStrategy.hpp"

class GridGamePlacement {
    protected:
        virtual bool canPlaceToken(const int line, const int col) const = 0;
};

#endif // GRIDGAMESTRATEGY_HPP