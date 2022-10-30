#ifndef GAME_H
#define GAME_H

#include <string>
#include <array>

#include "player.hpp"
#include "grid.hpp"

class Game {
    public:
        Game(Player playerA, Player playerB, int gridHeight, int gridWidth);
        ~Game();
        void startParty();
    private:
        Player playerA;
        Player playerB;
        Grid *grid;
};

#endif // GAME_H