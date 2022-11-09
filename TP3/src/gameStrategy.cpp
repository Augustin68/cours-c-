#include <iostream>
#include "gameStrategy.hpp"

GameStrategy::GameStrategy(int colNbr, int lineNbr) {
    this->grid = new Grid(lineNbr, colNbr);
}

GameStrategy::~GameStrategy() {
    delete this->grid;
}

bool GameStrategy::isMaxRoundReached(int roundCount) const {
    return this->grid->getColNbr() * this->grid->getLineNbr() <= roundCount ? true : false;
}
