#include <iostream>
#include <string>

#include "player.hpp"

int main() {
    std::cout << "Coucou tick tack" << std::endl;

    Player* player = new Player("coucou", 'b');

    std::cout << "Player name: " << player->getName() << std::endl;
    std::cout << "Player symboil: " << player->getSymbol() << std::endl;
    delete player;
    return 0;
}