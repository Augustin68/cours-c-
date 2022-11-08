#include "gameTicTacToe.hpp"
#include "grid.hpp"

GameTicTacToe::GameTicTacToe() {
    this->grid = new Grid(3, 3);
    this->grid->displayGrid();
}