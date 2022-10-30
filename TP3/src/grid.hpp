#ifndef GRID_HPP
#define GRID_HPP

#include <array>

class Grid {
    public:
        Grid();
        void placeElement(int x, int y, char element);
    private:
        std::array<std::array<char, 3>, 3> grid;
};

#endif //GRID_HPP