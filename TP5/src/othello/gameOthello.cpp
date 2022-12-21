#include "gameOthello.hpp"

GameOthello::GameOthello() : GameStrategy(8, 8) {
    
    // TODO : implémenter le pré-traitement de la grille d'une meilleure manière
    this->grid->placeElement(4, 4, 'X');
    this->grid->placeElement(5, 5, 'X');

    this->grid->placeElement(4, 5, 'O');
    this->grid->placeElement(5, 4, 'O');
}

// TODO : renommer "symbol" en un truc plus explicite partout dans le code ("playerToken" ?)
bool GameOthello::canPlaceToken(const int line, const int col, const char symbol) const {

    if(line < 1 || line > this->grid->getLineNbr() || col < 1 || col > this->grid->getColNbr()) {
        std::cout << "Impossible de jouer ici : Tes coordonnées ne sont pas comprise dans les limites de la grille !" << std::endl;
        return false;
    }
    
    if(this->grid->getElement(line, col) != '-') {
        std::cout << "Impossible de jouer ici : Un autre élement est déjà présent sur cette case !" << std::endl;
        return false;
    }

    if(this->checkAdjacentEnemyToken(line, col, symbol)) {
        std::cout << "Impossible de jouer ici : vous devez jouer a coté d'un pion" << std::endl;
        return false;
    }



    return true;
}

Position GameOthello::placeToken(const char symbol) const {
    this->grid->displayGrid();
    Position pos;
    bool validInput = false;
    do {
        std::cout << "Entre les coordonnées de la case (ligne,colonne) : ";
        std::string input;
        std::cin >> input;
        validInput = parsePositionInput(input, pos);
    } while(!validInput && this->canPlaceToken(pos.line, pos.column, symbol));

    this->grid->placeElement(pos.line, pos.column, symbol);

    if(this->grid->getElement(pos.line + 1, pos.column) != '-' && this->grid->getElement(pos.line + 1, pos.column) != symbol) {
        for(
            int i = 1; 
            this->grid->getElement(pos.line + i, pos.column) != '-' && 
            this->grid->getElement(pos.line + i, pos.column) != symbol &&
            this->grid->getLineNbr() > pos.line + i;
            i++     
        ) {
            this->grid->placeElement(pos.line + i, pos.column, symbol);
        }
    }

    // TODO : faire tout ça pour le reste (et de manière + clean ?)

    return pos;
}

bool GameOthello::checkWin(const Position lastPlayPos) const {
    
    char playedSymbol = this->grid->getElement(lastPlayPos.line, lastPlayPos.column);

    // TODO : prendre en charge la situation ou plus aucun joueur ne peut jouer mais que la grille n'est pas pleine
    // dépend du canPlaceToken
    if(this->grid->numberOfSymbolInGrid('-') == 0) {
        int numberOfSymbol = this->grid->numberOfSymbolInGrid(playedSymbol);

        // TODO : faire de même avec le symbole du joueur adverse
        // TODO : resortir quel joueur gagne
    }

    return false;
}

// TODO : renommer col en column
bool GameOthello::checkAdjacentEnemyToken(const int line, const int col, const char symbol) const {

    // TODO : renommer les fonctions dans this->grid
    for(int currentLine = line - 1; currentLine <= line + 1 && currentLine < this->grid->getLineNbr(); currentLine++) {
        for(int currentColumn = col - 1; currentColumn <= col + 1 && currentColumn < this->grid->getColNbr(); currentColumn++) {
            if(this->grid->getElement(currentLine, currentColumn) != '-' && this->grid->getElement(currentLine, currentColumn) != symbol)
                return true;
        }
    }

    return false;
}

bool GameOthello::checkOtherTokenAligned(const int line, const int col, const char symbol) const {

    // check en ligne
    for(int i = 0; line + i < this->grid->getLineNbr() && line - i > 0; i++) {
        if(this->grid->getElement(line + i, col) == symbol) return true;
        if(this->grid->getElement(line - i, col) == symbol) return true;
    }

    // check en colonne
    for(int j = 0; col + j < this->grid->getColNbr() && col - j > 0; j++) {
        if(this->grid->getElement(line, col + j) == symbol) return true;
        if(this->grid->getElement(line, col - j) == symbol) return true;
    }

    return false;
}