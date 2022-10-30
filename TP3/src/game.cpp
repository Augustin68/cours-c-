#include <iostream>

#include "game.hpp"
#include "player.hpp"
#include "grid.hpp"

Game::Game(Player playerA, Player playerB, int gridHeight, int gridWidth) {
    this->playerA = playerA;
    this->playerB = playerB;
    this->grid = new Grid();
};

Game::~Game() {};

void Game::startParty() {
    std::cout << "Bienvenu dans la partie !" << std::endl;
    std::cout << "Acclamons nos deux joueurs : " 
        << this->playerA.getName() << " (" << this->playerA.getSymbol() << ")"
        << " et " 
        << this->playerB.getName() << " (" << this->playerB.getSymbol() << ")"
        << " !!" << std::endl;
}