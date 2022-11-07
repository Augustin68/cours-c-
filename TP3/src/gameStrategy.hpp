#ifndef GAME_STRATEGY
#define GAME_STRATEGY

#include <string>

class GameStrategy {
    public:
        virtual ~GameStrategy() = default;
        virtual void placeToken() const = 0;
        virtual void checkWin() const = 0;
};
#endif // GAME_STRATEGY