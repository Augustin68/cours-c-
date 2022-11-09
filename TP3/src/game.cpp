#include <iostream>
#include <string>

#include "game.hpp"

Game::Game() { };

Game::~Game() {
    delete this->playerA;
    delete this->playerB;
};

void Game::startParty() {
    std::cout << "Bienvenu dans la partie !" << std::endl;
    std::cout << std::endl;
    
    this->createPlayers();

    std::cout << "Acclamons nos deux joueurs : " 
        << this->playerA->getName() << " (" << this->playerA->getSymbol() << ")"
        << " et " 
        << this->playerB->getName() << " (" << this->playerB->getSymbol() << ")"
        << " !!" << std::endl;

    GameContext context(std::make_unique<GameConnectFour>());

    std::cout << std::endl;

    int playerGame = 0;
    do {
        std::cout << "A quoi voulez-vous jouer ? " << std::endl;
        std::cout << "1 - Morpion" << std::endl;
        std::cout << "2 - Puissance 4" << std::endl;
        std::cout << "Entrez 1 ou 2 ici : ";
        std::cin >> playerGame;

    } while (playerGame != 1 && playerGame != 2);

    switch (playerGame)
    {
    case 1:
        context.set_strategy(std::make_unique<GameTicTacToe>());
        break;
    case 2:
        context.set_strategy(std::make_unique<GameConnectFour>());
        break;
    
    default:
        break;
    }

    int roundCount = 1;

    do {
        std::cout << "===== Tour n°" << roundCount << "=====" << std::endl;

        // std::cout << "> C'est au tour de " << this->playerA->getName() << " (" << this->playerA->getSymbol() << ")" << std::endl;
        // context.placeToken(this->playerA->getSymbol());
        
        // std::cout << "> C'est au tour de " << this->playerB->getName() << " (" << this->playerB->getSymbol() << ")" << std::endl;
        // context.placeToken(this->playerB->getSymbol());

        this->playRound(this->playerA, context);
        this->playRound(this->playerB, context);

        roundCount++;
    } while(true);
}

void Game::playRound(Player *player, GameContext &context) const {
    std::cout << "> C'est au tour de " << player->getName() << " (" << player->getSymbol() << ")" << std::endl;
    Position lastPlayedPosition = context.placeToken(player->getSymbol());
    context.checkWin(lastPlayedPosition);
}

void Game::createPlayers() {
    std::cout << "Entrez le nom du joueur A : ";
    std::string playerAName;
    std::cin >> playerAName;
    std::cout << "Entrez le nom du joueur B : ";
    std::string playerBName;
    std::cin >> playerBName;
    this->playerA = new Player(playerAName, 'X');
    this->playerB = new Player(playerBName, 'O');
}