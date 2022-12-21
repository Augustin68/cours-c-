#include "player.hpp"

Player::Player(const std::string name, const char token){
    this->name = name;
    this->token = token;
}
Player::Player(){}

Player::~Player() {}