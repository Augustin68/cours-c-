#include "player.hpp"

Player::Player(std::string name, char symbol){
    this->name = name;
    this->symbol = symbol;
}
Player::Player(){}

Player::~Player() {}

std::string Player::getName() const {
    return this->name;
}

char Player::getSymbol() const {
    return this->symbol;
}