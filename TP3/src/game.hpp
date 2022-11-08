#ifndef GAME_H
#define GAME_H

#include <string>
#include <array>

#include "player.hpp"
#include "grid.hpp"

class Game {
    public:
        Game();
        ~Game();
        void startParty();
    private:
        Player *playerA;
        Player *playerB;
};

#endif // GAME_H