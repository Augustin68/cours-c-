#include <string>

#include "gameConnectFour.hpp"

GameConnectFour::GameConnectFour() : GameStrategy(4, 7) {
};

Position GameConnectFour::placeToken(char symbol) const{
    this->grid->displayGrid();
    Position pos;
    pos.line = 0;
    do {
        std::cout << "Entre le numéro de la colonne : ";
        std::cin >> pos.column;
        std::cout << std::endl;
    } while(!this->canPlaceToken(pos.column));


    int lowestLine = this->grid->getLineNbr();
    while(this->grid->getElement(lowestLine, pos.column) != '-') {
        lowestLine--;
    }
    pos.line = lowestLine;
    this->grid->placeElement(pos.line, pos.column, symbol);
    return pos;
}


bool GameConnectFour::canPlaceToken(int col) const {
    if(col < 1 || col > this->grid->getColNbr()) {
        std::cout << "Impossible de jouer ici : Le numéro de colonne n'est pas compris dans les limites de la grille !" << std::endl;
        return false;
    }

    if(this->grid->getElement(1, col) != '-') {
        std::cout << "Impossible de jouer ici : La colonne est pleine !" << std::endl;
        return false;
    }
    return true;
}

bool GameConnectFour::checkWin(Position lastPlayPos) const {
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