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
        std::vector<Player*> players;
        void createPlayers();
        bool playRound(Player *player, GameContext &context) const;
        bool isEquality(GameContext &context, int playedCount) const;
};

#endif // GAME_H