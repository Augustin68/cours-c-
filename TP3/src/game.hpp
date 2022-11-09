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
        Player *playerA;
        Player *playerB;
        void createPlayers();
        bool playRound(Player *player, GameContext &context) const;
        bool isEquality(GameContext &context, int playedCount) const;
};

#endif // GAME_H