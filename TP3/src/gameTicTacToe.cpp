#include "gameTicTacToe.hpp"
#include "grid.hpp"

GameTicTacToe::GameTicTacToe() : GameStrategy(new Grid(3, 3)) {
    this->grid->displayGrid();
}

GameTicTacToe::~GameTicTacToe() { }