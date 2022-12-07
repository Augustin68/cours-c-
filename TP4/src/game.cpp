#include <iostream>
#include <string>

#include "game.hpp"

Game::Game() {
    this->context = new GameContext();
 };

Game::~Game() {
    for(int i = 0; i < (int)this->players.size(); i++) {
        delete this->players[i];
    }
    delete this->context;
};

void Game::startParty() {
    std::cout << "Bienvenu dans la partie !" << std::endl;
    std::cout << std::endl;
    
    this->createPlayers();
    std::cout << "Acclamons ";
    for(int i = 0; i < (int)this->players.size(); i++) {
        std::cout << this->players[i]->getName() << " (" << this->players[i]->getSymbol() << ")";
        if(i < (int)this->players.size() - 1) {
            std::cout << " et ";
        }
    }
    std::cout << ", nos joueurs !! !!" << std::endl;
    std::cout << std::endl;

    this->selectGame();

    this->playGame();
}

void Game::playGame() const {
    int roundCount = 1;
    int playedCount = 0;
    bool gameStopped = false;
    do {
        std::cout << "===== Tour n°" << roundCount << " =====" << std::endl;

        for(int i = 0; i < (int)this->players.size(); i++) {
            if(this->playRound(this->players[i])) { gameStopped = true;  break; };
            playedCount++;
            if(this->isEquality(playedCount)) { gameStopped = true; break; }
        }
        
        roundCount++;
    } while(!gameStopped);
}

bool Game::isEquality(const int playedCount) const {
    if(this->context->isMaxRoundReached(playedCount)) {
        std::cout << std::endl;
        std::cout << "!!! EGALITE !!! > La grille est pleine et aucun joueur n'a gagné..." << std::endl;
        return true;
    }
    return false;
}

bool Game::playRound(const Player *player) const {
    std::cout << "> C'est au tour de " << player->getName() << " (" << player->getSymbol() << ")" << std::endl;
    Position lastPlayedPosition = this->context->placeToken(player->getSymbol());
    if(this->context->checkWin(lastPlayedPosition)) {
            std::cout << std::endl;
        std::cout << "!!! LE JOUEUR " << player->getName() << " A GAGNE !!!" << std::endl;
        return true;
    };
    return false;
}

void Game::createPlayers() {
    std::cout << "Entrez le nom du joueur A : ";
    std::string playerAName;
    std::cin >> playerAName;
    std::cout << "Entrez le nom du joueur B : ";
    std::string playerBName;
    std::cin >> playerBName;

    this->players.push_back(new Player(playerAName, 'X'));
    this->players.push_back(new Player(playerBName, 'O'));
}

void Game::selectGame() const {
    int selectedGame = 0;
    do {
        std::cout << "A quoi voulez-vous jouer ? " << std::endl;
        std::cout << "1 - Morpion" << std::endl;
        std::cout << "2 - Puissance 4" << std::endl;
        std::cout << "Entrez 1 ou 2 ici : ";
        std::cin >> selectedGame;
        std::cout << std::endl;

    } while (selectedGame != 1 && selectedGame != 2);

    
    switch (selectedGame)
    {
    case 1:
        std::cout << "Vous avez choisi le morpion !" << std::endl;
        this->context->set_strategy(std::make_unique<GameTicTacToe>());
        break;
    case 2:
        std::cout << "Vous avez choisi le puissance 4 !" << std::endl;
        this->context->set_strategy(std::make_unique<GameConnectFour>());
        break;
    
    default:
        break;
    }
}