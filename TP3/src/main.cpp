#include <iostream>
#include <string>

#include "player.hpp"
#include "game.hpp"

int main() {
    std::cout << "Coucou tick tack" << std::endl;

    Player* playerA = new Player("Chloe", 'X');
    Player* playerB = new Player("Jeannine", 'O');

    // The 2 last arguments is unused for the moment !
    Game* game = new Game(*playerA, *playerB, 3, 3);
    game->startParty();

    delete playerA;
    delete playerB;
    delete game;
    
    return 0;
}