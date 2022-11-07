#include <iostream>

#include "game.hpp"
#include "player.hpp"
#include "grid.hpp"
#include "gameContext.hpp"
#include "gameConnectFour.hpp"
#include "gameTicTacToe.hpp"

Game::Game(Player playerA, Player playerB, int gridHeight, int gridWidth) {
    this->playerA = playerA;
    this->playerB = playerB;
    this->grid = new Grid();
};

Game::~Game() {
    delete this->grid;
};

void Game::startParty() {
    std::cout << "Bienvenu dans la partie !" << std::endl;
    std::cout << "Acclamons nos deux joueurs : " 
        << this->playerA.getName() << " (" << this->playerA.getSymbol() << ")"
        << " et " 
        << this->playerB.getName() << " (" << this->playerB.getSymbol() << ")"
        << " !!" << std::endl;

    GameContext context(std::make_unique<GameConnectFour>());
    std::cout << "Game strategy is setted via constructor on connect four :" << std::endl;
    context.placeToken();

    context.set_strategy(std::make_unique<GameTicTacToe>());
    std::cout << "Game strategy is now tic tac toe" << std::endl;
    context.placeToken();
}