#include "gameTicTacToe.hpp"

GameTicTacToe::GameTicTacToe() : GameStrategy(3, 3) {
}

Position GameTicTacToe::placeToken(char symbol) const{
    this->grid->displayGrid();
    Position pos;
    do {
        std::cout << "Entre les coordonnées de la case (ligne,colonne) : ";
        if(scanf("%d,%d", &pos.line, &pos.column)>0){};
    } while(!this->canPlaceToken(pos.line, pos.column));

    this->grid->placeElement(pos.line, pos.column, symbol);
    return pos;
}


bool GameTicTacToe::canPlaceToken(int line, int col) const {
    if(line < 1 || line > 3 || col < 1 || col > 3) {
        std::cout << "Impossible de jouer ici : Tes coordonnées ne sont pas comprise dans les limites de la grille !" << std::endl;
        return false;
    }
    if(this->grid->getElement(line, col) != '-') {
        std::cout << "Impossible de jouer ici : Un autre élement est déjà présent sur cette case !" << std::endl;
        return false;
    }
    return true;
}

bool GameTicTacToe::checkWin(Position lastPlayPos) const {
    if(this->grid->horizontalContiguousCount(lastPlayPos) >= 3
        || this->grid->verticalContiguousCount(lastPlayPos) >= 3
        || this->grid->topLeftToBottomRightDiagonalContiguousCount(lastPlayPos) >= 3
        || this->grid->bottomLeftToTopRightDiagonalContiguousCount(lastPlayPos) >= 3
    ) {
        return true;
    }


    return false;
}
