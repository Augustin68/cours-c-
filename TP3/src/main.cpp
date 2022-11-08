#include "game.hpp"


int main() {
    Game* game = new Game();
    game->startParty();

    delete game;
    return 0;
}