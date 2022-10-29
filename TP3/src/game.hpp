#ifndef GAME_H
#define GAME_H

#include <string>
#include <array>

#include "player.hpp"

class Game {
    public:
        Game(Player playerA, Player playerB, int gridHeight, int gridWidth);
        ~Game();
    private:
        const Player playerA;
        const Player playerB;
        const std::array<std::array<char, 6>, 5> grid;
};

#endif // GAME_H