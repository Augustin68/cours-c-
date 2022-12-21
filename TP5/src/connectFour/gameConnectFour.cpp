#include <string>

#include "gameConnectFour.hpp"
#include "../shared/utils.hpp"

GameConnectFour::GameConnectFour() : GameStrategy(4, 7) {
};

Position GameConnectFour::placeToken(const char token) const{
    this->grid->displayGrid();
    Position pos;
    pos.line = 0;
    do {
        std::cout << "Entre le numéro de la colonne : ";
        pos.column = readInt();
        std::cout << std::endl;
    } while(!this->canPlaceToken(pos.column));


    int lowestLine = this->grid->getLineNbr();
    while(this->grid->getElement(lowestLine, pos.column) != '-') {
        lowestLine--;
    }
    pos.line = lowestLine;
    this->grid->placeElement(pos.line, pos.column, token);
    return pos;
}


bool GameConnectFour::canPlaceToken(const int column) const {
    if(column < 1 || column > this->grid->getColNbr()) {
        std::cout << "Impossible de jouer ici : Le numéro de colonne n'est pas compris dans les limites de la grille !" << std::endl;
        return false;
    }

    if(this->grid->getElement(1, column) != '-') {
        std::cout << "Impossible de jouer ici : La colonne est pleine !" << std::endl;
        return false;
    }
    return true;
}

bool GameConnectFour::checkWin(const Position lastPlayPos) const {
    if(this->grid->horizontalContiguousCount(lastPlayPos) >= 4
        || this->grid->verticalContiguousCount(lastPlayPos) >= 4
        || this->grid->topLeftToBottomRightDiagonalContiguousCount(lastPlayPos) >= 4
        || this->grid->bottomLeftToTopRightDiagonalContiguousCount(lastPlayPos) >= 4
    ) {
        this->grid->displayGrid();
        return true;
    }


    return false;
}