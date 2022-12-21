#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <array>

#include "player.hpp"
#include "generic/game/gameContext.hpp"
#include "ticTacToe/gameTicTacToe.hpp"
#include "connectFour/gameConnectFour.hpp"
#include "othello/gameOthello.hpp"

class Game {
    public:
        Game();
        ~Game();
        void startGame();
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