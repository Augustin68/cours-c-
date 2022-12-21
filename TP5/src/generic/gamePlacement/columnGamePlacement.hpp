#ifndef COLUMNGAMESTRATEGY_HPP
#define COLUMNGAMESTRATEGY_HPP

#include "../game/gameStrategy.hpp"

class ColumnGridPlacement {
    protected:
        virtual bool canPlaceToken(const int column) const = 0;
};

#endif // COLUMNGAMESTRATEGY_HPP