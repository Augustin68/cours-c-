#include <string>

#include "gameConnectFour.hpp"

GameConnectFour::GameConnectFour() : GameStrategy(new Grid(4, 7)) {
};

Position GameConnectFour::placeToken(char symbol) const {
    std::cout << "yes" << std::endl;
}

bool GameConnectFour::checkWin(Position lastPlayPos) const {
    return false;
}

bool GameConnectFour::canPlaceToken(int line, int col) const {
   return true;
}