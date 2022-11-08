#include "gameConnectFour.hpp"
#include "grid.hpp"
GameConnectFour::GameConnectFour() {
    this->grid = new Grid(4, 7);
    this->grid->displayGrid();
};