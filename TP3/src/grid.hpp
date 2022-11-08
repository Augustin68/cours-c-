#ifndef GRID_HPP
#define GRID_HPP

#include <array>
#include <vector>

class Grid {
    public:
        Grid(int lines, int columns);
        ~Grid();
        void placeElement(int x, int y, char element);
        void displayGrid() const;
    private:
        std::vector<std::vector<char>> grid {{}};
};

#endif //GRID_HPP