#include "grid.hpp"

Grid::Grid(const int lines, const int columns) {
    this->grid.clear();
    this->grid.resize(lines, std::vector<char>(columns, '-'));
}

Grid::~Grid() { }

void Grid::placeElement(const int line, const int column, const char element) {
    this->grid[line - 1][column - 1] = element;
}

void Grid::displayGrid() const {
    std::cout << "  |";
    for(int i = 0; i < (int)this->grid[0].size(); i++) {
        std::cout << " " << i + 1 << " |";
    }
    std::cout << std::endl;
    std::cout << "  |";
    for(int i = 0; i < (int)this->grid[0].size(); i++) {
        std::cout << "___|";
    }
    std::cout << std::endl;
    for(int i = 0; i < (int)this->grid.size(); i++) {
        std::cout << i + 1 << " |";
        for(int j = 0; j < (int)this->grid[i].size(); j++) {
            std::cout << " " << this->grid[i][j] << " |";
        }
        std::cout << std::endl;
    }
}

int Grid::topLeftToBottomRightDiagonalContiguousCount(const Position pos) const {
    const int line = pos.line - 1;
    const int column = pos.column - 1;

    int count = 1;
    const char elementToCheck = this->grid[line][column];

    int checkedLine = line - 1;
    int checkedColumn = column - 1;
    // Ascending
    while(checkedLine >= 0 && checkedColumn >= 0) {
        if(this->grid[checkedLine][checkedColumn] == elementToCheck) {
            count ++;
        } else {
            break;
        }
        checkedLine--;
        checkedColumn--;
    }

    checkedLine = line + 1;
    checkedColumn = column + 1;
    // Descending
    while(checkedLine <= (int)this->grid.size() - 1 && checkedColumn <= (int)this->grid[0].size() - 1) {
        if(this->grid[checkedLine][checkedColumn] == elementToCheck) {
            count ++;
        } else {
            break;
        }
        checkedLine++;
        checkedColumn++;
    }

    return count;
}

int Grid::bottomLeftToTopRightDiagonalContiguousCount(const Position pos) const {
    const int line = pos.line - 1;
    const int column = pos.column - 1;

    int count = 1;
    const char elementToCheck = this->grid[line][column];

    int checkedLine = line - 1;
    int checkedColumn = column + 1;
    // Ascending
    while(checkedLine >= 0 && checkedColumn <= (int)this->grid[0].size() - 1) {
        if(this->grid[checkedLine][checkedColumn] == elementToCheck){
            count++;
        } else {
            break;
        }
        checkedLine--;
        checkedColumn++;
    }

    checkedLine = line + 1;
    checkedColumn = column - 1;
    // Descending
    while(checkedLine <= (int)this->grid.size() - 1 && checkedColumn >= 0) {
        if(this->grid[checkedLine][checkedColumn] == elementToCheck){
            count++;
        } else {
            break;
        }
        checkedLine++;
        checkedColumn--;
    }

    return count;
}

int Grid::verticalContiguousCount(const Position pos) const {
    const int line = pos.line - 1;
    const int column = pos.column - 1;

    int count = 1;
    const char elementToCheck = this->grid[line][column];

    // From element to bottom
    for(int i = line + 1; i < (int)this->grid.size(); i++) {
        if(this->grid[i][column] == elementToCheck) {
            count++;
        } else {
            break;
        }
    }

    // From elem to top
    for (int i = line - 1; i >= 0; i--) {
        if(this->grid[i][column] == elementToCheck) {
            count++;
        } else {
            break;
        }
    }

    return count;
}

int Grid::horizontalContiguousCount(const Position pos) const {
    const int line = pos.line - 1;
    const int column = pos.column - 1;
    
    int count = 1;

    const char elementToCheck = this->grid[line][column];
    // From element to right
    for(int i = column + 1; i < (int)this->grid[line].size(); i++) {
        if(this->grid[line][i] == elementToCheck){
            count++;
        } else {
            break;
        }
    }
    // From element to left
    for(int i = column - 1; i >= 0; i--) {
        if(this->grid[line][i] == elementToCheck){
            count++;
        } else {
            break;
        }
    }
    return count;
}