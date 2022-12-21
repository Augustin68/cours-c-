#include "gameOthello.hpp"

GameOthello::GameOthello() : GameStrategy(8, 8) {
    
    // TODO : implémenter le pré-traitement de la grille d'une meilleure manière
    this->grid->placeElement(4, 4, 'X');
    this->grid->placeElement(5, 5, 'X');

    this->grid->placeElement(4, 5, 'O');
    this->grid->placeElement(5, 4, 'O');
}

bool GameOthello::canPlaceToken(const int line, const int column, const char token) const {

    if(line < 1 || line > this->grid->getLineNbr() || column < 1 || column > this->grid->getColNbr()) {
        std::cout << "Impossible de jouer ici : Tes coordonnées ne sont pas comprise dans les limites de la grille !" << std::endl;
        return false;
    }
    
    if(this->grid->getElement(line, column) != '-') {
        std::cout << "Impossible de jouer ici : Un autre élement est déjà présent sur cette case !" << std::endl;
        return false;
    }

    if(this->checkAdjacentEnemyToken(line, column, token)) {
        std::cout << "Impossible de jouer ici : vous devez jouer a coté d'un pion" << std::endl;
        return false;
    }

    Position pos = Position();

    pos.column = column;
    pos.line = line;

    return this->grid->checkOtherTokenAligned(pos, token);
}

Position GameOthello::placeToken(const char token) const {
    this->grid->displayGrid();
    Position pos;
    bool validInput = false;
    do {
        std::cout << "Entre les coordonnées de la case (ligne,colonne) : ";
        std::string input;
        std::cin >> input;
        validInput = parsePositionInput(input, pos);
    } while(!validInput && this->canPlaceToken(pos.line, pos.column, token));

    this->grid->placeElement(pos.line, pos.column, token);

    this->flipTokens(pos, token);

    return pos;
}

bool GameOthello::checkWin(const Position lastPlayPos) const {
    
    char playedSymbol = this->grid->getElement(lastPlayPos.line, lastPlayPos.column);

    // TODO : prendre en charge la situation ou plus aucun joueur ne peut jouer mais que la grille n'est pas pleine
    // dépend du canPlaceToken
    if(this->grid->numberOfSymbolInGrid('-') == 0) {
        int numberOfSymbol = this->grid->numberOfSymbolInGrid(playedSymbol);

        // TODO : prendre en charge quand c'est l'adversaire qui gagne
        return this->grid->numberOfSymbolInGrid(this->grid->getElement(lastPlayPos.line, lastPlayPos.column)) > (this->grid->getLineNbr() * this->grid->getColNbr()) / 2;
    }

    return false;
}

bool GameOthello::checkAdjacentEnemyToken(const int line, const int column, const char token) const {

    for(int currentLine = line - 1; currentLine <= line + 1 && currentLine < this->grid->getLineNbr(); currentLine++) {
        for(int currentColumn = column - 1; currentColumn <= column + 1 && currentColumn < this->grid->getColNbr(); currentColumn++) {
            if(this->grid->getElement(currentLine, currentColumn) != '-' && this->grid->getElement(currentLine, currentColumn) != token)
                return true;
        }
    }

    return false;
}

// TODO : ca crash la dedans 
void GameOthello::flipTokens(const Position pos, const char token) const {
    // column
    if(this->grid->getElement(pos.line + 1, pos.column) != '-' && this->grid->getElement(pos.line + 1, pos.column) != token) {
        for(
            int i = 1; 
            this->grid->getElement(pos.line + i, pos.column) != '-' && 
            this->grid->getElement(pos.line + i, pos.column) != token &&
            this->grid->getLineNbr() > pos.line + i;
            i++     
        ) {
            this->grid->placeElement(pos.line + i, pos.column, token);
        }
    }

    if(this->grid->getElement(pos.line - 1, pos.column) != '-' && this->grid->getElement(pos.line - 1, pos.column) != token) {
        for(
            int i = 1; 
            this->grid->getElement(pos.line - i, pos.column) != '-' && 
            this->grid->getElement(pos.line - i, pos.column) != token &&
            0 < pos.line - i;
            i++     
        ) {
            this->grid->placeElement(pos.line - i, pos.column, token);
        }
    }

    // line
    if(this->grid->getElement(pos.line, pos.column + 1) != '-' && this->grid->getElement(pos.line, pos.column + 1) != token) {
        for(
            int i = 1; 
            this->grid->getElement(pos.line, pos.column + i) != '-' && 
            this->grid->getElement(pos.line, pos.column + i) != token &&
            this->grid->getColNbr() > pos.column + i;
            i++     
        ) {
            this->grid->placeElement(pos.line, pos.column + i, token);
        }
    }

    if(this->grid->getElement(pos.line, pos.column - 1) != '-' && this->grid->getElement(pos.line, pos.column - 1) != token) {
        for(
            int i = 1; 
            this->grid->getElement(pos.line, pos.column - i) != '-' && 
            this->grid->getElement(pos.line, pos.column - i) != token &&
            0 < pos.column - i;
            i++     
        ) {
            this->grid->placeElement(pos.line, pos.column - i, token);
        }
    }

    // diags
    if(this->grid->getElement(pos.line + 1, pos.column + 1) != '-' && this->grid->getElement(pos.line + 1, pos.column + 1) != token) {
        for(
            int i = 1; 
            this->grid->getElement(pos.line + i, pos.column + i) != '-' && 
            this->grid->getElement(pos.line + i, pos.column + i) != token &&
            this->grid->getColNbr() > pos.column + i &&
            this->grid->getLineNbr() > pos.line + i;
            i++     
        ) {
            this->grid->placeElement(pos.line + i, pos.column + i, token);
        }
    }

    if(this->grid->getElement(pos.line - 1, pos.column - 1) != '-' && this->grid->getElement(pos.line - 1, pos.column - 1) != token) {
        for(
            int i = 1; 
            this->grid->getElement(pos.line - i, pos.column - i) != '-' && 
            this->grid->getElement(pos.line - i, pos.column - i) != token &&
            0 < pos.column - i &&
            0 < pos.line - i;
            i++     
        ) {
            this->grid->placeElement(pos.line - i, pos.column - i, token);
        }
    }

    if(this->grid->getElement(pos.line - 1, pos.column + 1) != '-' && this->grid->getElement(pos.line - 1, pos.column + 1) != token) {
        for(
            int i = 1; 
            this->grid->getElement(pos.line - i, pos.column + i) != '-' && 
            this->grid->getElement(pos.line - i, pos.column + i) != token &&
            this->grid->getColNbr() > pos.column + i &&
            0 < pos.line - i;
            i++     
        ) {
            this->grid->placeElement(pos.line - i, pos.column + i, token);
        }
    }
 
    if(this->grid->getElement(pos.line + 1, pos.column - 1) != '-' && this->grid->getElement(pos.line + 1, pos.column - 1) != token) {
        for(
            int i = 1; 
            this->grid->getElement(pos.line + i, pos.column - i) != '-' && 
            this->grid->getElement(pos.line + i, pos.column - i) != token &&
            0 < pos.column - i &&
            this->grid->getLineNbr() > pos.line + i;
            i++     
        ) {
            this->grid->placeElement(pos.line - i, pos.column - i, token);
        }
    }
}