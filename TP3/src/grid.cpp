#include <vector>
#include <iostream>
#include "grid.hpp"

Grid::Grid(int lines, int columns) {
    this->grid.clear();
    this->grid.resize(lines, std::vector<char>(columns, '-'));
}

Grid::~Grid() { }

void Grid::placeElement(int line, int column, char element) {
    this->grid[line - 1][column - 1] = element;
}

char Grid::getElement(int line, int column) const {
    return this->grid[line - 1][column - 1];
};


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

int Grid::verticalContiguousCount(const Position pos) const {
    int line = pos.line - 1;
    int column = pos.column - 1;

    int count = 1;
    char elementToCheck = this->grid[line][column];

    // From element to bottom
    for(int i = line + 1; i < this->grid.size(); i++) {
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
    int line = pos.line - 1;
    int column = pos.column - 1;
    
    int count = 1;

    char elementToCheck = this->grid[line][column];
    // std::cout << "element to check: " << elementToCheck << std::endl;
    // From element to right
    for(int i = column + 1; i < this->grid[line].size(); i++) {
        if(this->grid[line][i] == elementToCheck){
            // std::cout << "e to R +1 car " << line << ":" << i << " = elem: " << elementToCheck << std::endl;
            count++;
        } else {
            break;
        }
    }
    // From element to left
    for(int i = column - 1; i >= 0; i--) {
        if(this->grid[line][i] == elementToCheck){
            // std::cout << "e to left +1 car " << line << ":" << i << " = elem: " << elementToCheck << std::endl;
            count++;
        } else {
            break;
        }
    }
    return count;
}