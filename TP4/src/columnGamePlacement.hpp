#ifndef COLUMNGAMESTRATEGY_HPP
#define COLUMNGAMESTRATEGY_HPP

#include "gameStrategy.hpp"

class ColumnGridPlacement {
    protected:
        virtual bool canPlaceToken(const int col) const = 0;
};

#endif // COLUMNGAMESTRATEGY_HPP