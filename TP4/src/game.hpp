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
        void playGame() const;
        bool playRound(const Player *player) const;
        bool isEquality(const int playedCount) const;
        void selectGame() const;
};

#endif // GAME_H