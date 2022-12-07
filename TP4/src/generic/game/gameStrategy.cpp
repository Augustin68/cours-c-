#include <iostream>

#include "gameStrategy.hpp"

GameStrategy::GameStrategy(const int lineNbr, const int colNbr) {
    this->grid = new Grid(lineNbr, colNbr);
}

GameStrategy::~GameStrategy() {
    delete this->grid;
}

bool GameStrategy::isMaxRoundReached(const int roundCount) const {
    return this->grid->getColNbr() * this->grid->getLineNbr() <= roundCount ? true : false;
}