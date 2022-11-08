#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <array>

#include "gameConnectFour.hpp"
#include "gameContext.hpp"
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
        void createPlayers();
};

#endif // GAME_H