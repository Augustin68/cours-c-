#ifndef GAME_STRATEGY
#define GAME_STRATEGY

#include "../../grid.hpp"
#include "../grid/position.hpp"

class GameStrategy {
    public:
        GameStrategy(const int colNbr, const int lineNbr);
        virtual ~GameStrategy();
        virtual Position placeToken(const char symbol) const = 0;
        virtual bool checkWin(const Position lastPlayPos) const = 0;
        bool isMaxRoundReached(const int roundCount) const;
    protected:
        Grid *grid;
};
#endif // GAME_STRATEGY