#ifndef GAME_STRATEGY
#define GAME_STRATEGY

#include <string>

#include "grid.hpp"
#include "position.hpp"

class GameStrategy {
    public:
        GameStrategy(Grid *grid);
        virtual ~GameStrategy();
        virtual Position placeToken(char symbol) const = 0;
        virtual bool checkWin(Position lastPlayPos) const = 0;
    protected:
        Grid *grid;
        virtual bool canPlaceToken(int line, int col) const = 0;
};
#endif // GAME_STRATEGY