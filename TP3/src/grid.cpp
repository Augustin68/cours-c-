#include <vector>
#include <iostream>
#include "grid.hpp"

Grid::Grid(int lines, int columns) {
    this->grid.resize(lines, std::vector<char>(columns, '-'));
}

Grid::~Grid() { }

void Grid::displayGrid() const {
    std::cout << "==========" << std::endl;
    for(int i = 0; i < (int)this->grid.size(); i++) {
        for(int j = 0; j < (int)this->grid[i].size(); j++) {
            std::cout << " " << this->grid[i][j] << " |";
        }
        std::cout << std::endl;
    }
    std::cout << "==========" << std::endl;
}