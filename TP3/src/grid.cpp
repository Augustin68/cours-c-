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