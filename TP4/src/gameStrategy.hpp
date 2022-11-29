#ifndef GAME_STRATEGY
#define GAME_STRATEGY

#include "grid.hpp"
#include "position.hpp"

class GameStrategy {
    public:
        GameStrategy(int colNbr, int lineNbr);
        virtual ~GameStrategy();
        virtual Position placeToken(char symbol) const = 0;
        virtual bool checkWin(Position lastPlayPos) const = 0;
        bool isMaxRoundReached(int roundCount) const;
    protected:
        Grid *grid;
        virtual bool canPlaceToken(int line, int col) const = 0;
};
#endif // GAME_STRATEGY