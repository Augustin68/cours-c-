#include <string>

#include "gameConnectFour.hpp"

GameConnectFour::GameConnectFour() : GameStrategy(4, 7) {
};

Position GameConnectFour::placeToken(char symbol) const {
    std::cout << "yes" << std::endl;

    return Position();
}

bool GameConnectFour::checkWin(Position lastPlayPos) const {
    return false;
}

bool GameConnectFour::canPlaceToken(int line, int col) const {
   return true;
}