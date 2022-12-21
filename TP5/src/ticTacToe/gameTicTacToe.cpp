#include "gameTicTacToe.hpp"

GameTicTacToe::GameTicTacToe() : GameStrategy(3, 3) {
}

Position GameTicTacToe::placeToken(const char symbol) const{
    this->grid->displayGrid();
    Position pos;
    bool validInput = false;
    do {
        std::cout << "Entre les coordonnées de la case (ligne,colonne) : ";
        std::string input;
        std::cin >> input;
        validInput = parsePositionInput(input, pos);
    } while(!validInput && this->canPlaceToken(pos.line, pos.column));

    this->grid->placeElement(pos.line, pos.column, symbol);
    return pos;
}


bool GameTicTacToe::canPlaceToken(const int line, const int col) const {
    if(line < 1 || line > this->grid->getLineNbr() || col < 1 || col > this->grid->getColNbr()) {
        std::cout << "Impossible de jouer ici : Tes coordonnées ne sont pas comprise dans les limites de la grille !" << std::endl;
        return false;
    }
    if(this->grid->getElement(line, col) != '-') {
        std::cout << "Impossible de jouer ici : Un autre élement est déjà présent sur cette case !" << std::endl;
        return false;
    }
    return true;
}

bool GameTicTacToe::checkWin(const Position lastPlayPos) const {
    if(this->grid->horizontalContiguousCount(lastPlayPos) >= 3
        || this->grid->verticalContiguousCount(lastPlayPos) >= 3
        || this->grid->topLeftToBottomRightDiagonalContiguousCount(lastPlayPos) >= 3
        || this->grid->bottomLeftToTopRightDiagonalContiguousCount(lastPlayPos) >= 3
    ) {
        this->grid->displayGrid();
        return true;
    }


    return false;
}
