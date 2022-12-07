#ifndef GRID_HPP
#define GRID_HPP

#include <iostream>
#include <array>
#include <vector>

#include "generic/grid/position.hpp"

class Grid {
    public:
        Grid(int lines, int columns);
        ~Grid();
        void placeElement(int line, int column, char element);
        void displayGrid() const;
        char getElement(int line, int column) const;
        int getLineNbr() const;
        int getColNbr() const;
        int horizontalContiguousCount(const Position pos) const;
        int verticalContiguousCount(const Position pos) const;
        int bottomLeftToTopRightDiagonalContiguousCount(const Position pos) const;
        int topLeftToBottomRightDiagonalContiguousCount(const Position pos) const;
    private:
        std::vector<std::vector<char>> grid {};
};

inline char Grid::getElement(int line, int column) const {
    return this->grid[line - 1][column - 1];
};

inline int Grid::getLineNbr() const {
    return this->grid.size();
}

inline int Grid::getColNbr() const {
    return this->grid[0].size();
}

#endif //GRID_HPP