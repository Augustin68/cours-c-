#include <iostream>
#include "gameStrategy.hpp"

GameStrategy::GameStrategy(Grid *grid) {
    this->grid = grid;
}

GameStrategy::~GameStrategy() {
    delete this->grid;
}