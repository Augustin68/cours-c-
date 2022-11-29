#ifndef GRID_HPP
#define GRID_HPP

#include <iostream>
#include <array>
#include <vector>

#include "position.hpp"

class Grid {
    public:
        Grid(int lines, int columns);
        ~Grid();
        void placeElement(int line, int column, char element);
        void displayGrid() const;
        inline char getElement(int line, int column) const;
        inline int getLineNbr() const;
        inline int getColNbr() const;
        int horizontalContiguousCount(const Position pos) const;
        int verticalContiguousCount(const Position pos) const;
        int bottomLeftToTopRightDiagonalContiguousCount(const Position pos) const;
        int topLeftToBottomRightDiagonalContiguousCount(const Position pos) const;
    private:
        std::vector<std::vector<char>> grid {};
};

#endif //GRID_HPP