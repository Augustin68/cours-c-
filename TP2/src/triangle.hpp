#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <array>
#include "point.hpp"

class Triangle {
    public:
        Triangle(Point pointA, Point pointB, Point pointC);
        ~Triangle();
        std::array<float, 3> getSideLengths();
        float getBase();
        float getHeight();
        float getArea();
        bool isIsosceles();
        bool isRectangle();
        bool isEquilateral();
    private:
        Point pointA;
        Point pointB;
        Point pointC;

};

#endif // TRIANGLE_H