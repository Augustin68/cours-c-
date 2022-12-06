#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <array>

#include "player.hpp"
#include "gameContext.hpp"
#include "gameTicTacToe.hpp"
#include "gameConnectFour.hpp"

class Game {
    public:
        Game();
        ~Game();
        void startParty();
    private:
        GameContext *context;
        std::vector<Player*> players;
        void createPlayers();
        bool playRound(Player *player) const;
        bool isEquality(int playedCount) const;
        int selectGame() const;
};

#endif // GAME_H