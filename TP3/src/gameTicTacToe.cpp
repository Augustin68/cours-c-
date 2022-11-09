#include "gameTicTacToe.hpp"

GameTicTacToe::GameTicTacToe() : GameStrategy(new Grid(3, 3)) {
}

GameTicTacToe::~GameTicTacToe() { }

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
    std::cout << "on peut placer" << std::endl;
    return true;
}

bool GameTicTacToe::checkWin(Position lastPlayPos) const {
    std::cout << "Vérification de la victoire avec la dernière position en " << lastPlayPos.line << " " << lastPlayPos.column << std::endl;

    // std::cout << "Nombre de signes contigus horizontaux: " << this->grid->horizontalContiguousCount(lastPlayPos) << std::endl;
    // std::cout << "Nombre de signes contigus verticaux: " << this->grid->verticalContiguousCount(lastPlayPos) << std::endl;
    std::cout << "Nombre de signes contigus BL to TR: " << this->grid->bottomLeftToTopRightDiagonalContiguousCount(lastPlayPos) << std::endl;

    // int widthCount = 0;
    // for(int i = lastPlayPos.column; i < );


    return false;
}
