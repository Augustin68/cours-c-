#include <string>
#include "player.hpp"

Player::Player(std::string name, char symbol){
    this->name = name;
    this->symbol = symbol;
}

Player::~Player() {}

std::string Player::getName() {
    return this->name;
}

char Player::getSymbol() {
    return this->symbol;
}