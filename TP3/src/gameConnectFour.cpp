#include <string>

#include "gameConnectFour.hpp"
#include "grid.hpp"

GameConnectFour::GameConnectFour() : GameStrategy(new Grid(4, 7)) {
    this->grid->displayGrid();
};

void GameConnectFour::placeToken(char symbol) const {
    std::cout << "yes" << std::endl;
}
