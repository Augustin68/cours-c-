#include <iostream>
#include <string>

#include "game.hpp"
#include "player.hpp"
#include "grid.hpp"
#include "gameContext.hpp"
#include "gameConnectFour.hpp"
#include "gameTicTacToe.hpp"

Game::Game() { 
    this->playerA = new Player("dsqfmlkj", 'c');
    this->playerB = new Player("qsdfmoijqsfd", 'o');
};

Game::~Game() {
    delete this->playerA;
    delete this->playerB;
};

void Game::startParty() {
    std::cout << "Bienvenu dans la partie !" << std::endl;
    std::cout << std::endl;
    // std::cout << "Entrez le nom du joueur A : ";
    // std::string playerAName;
    // std::cin >> playerAName;
    // std::cout << "Entrez le nom du joueur B : ";
    // std::string playerBName;
    // std::cin >> playerBName;
    // this->playerA = new Player(playerAName, 'X');
    // this->playerB = new Player(playerBName, 'O');

    // std::cout << "Acclamons nos deux joueurs : " 
    //     << this->playerA->getName() << " (" << this->playerA->getSymbol() << ")"
    //     << " et " 
    //     << this->playerB->getName() << " (" << this->playerB->getSymbol() << ")"
    //     << " !!" << std::endl;

    GameContext context(std::make_unique<GameConnectFour>());

    // context->set_strategy(std::make_unique<GameConnectFour>());

}