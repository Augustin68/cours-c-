#ifndef GAME_STRATEGY
#define GAME_STRATEGY

#include <string>

#include "grid.hpp"

class GameStrategy {
    public:
        virtual ~GameStrategy() {
            delete this->grid;
        };
        virtual void placeToken() const = 0;
        virtual void checkWin() const = 0;
    protected:
        Grid *grid;
};
#endif // GAME_STRATEGY