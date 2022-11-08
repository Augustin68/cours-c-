#include "gameConnectFour.hpp"
#include "grid.hpp"

GameConnectFour::GameConnectFour() : GameStrategy(new Grid(4, 7)) {
    this->grid->displayGrid();
};
