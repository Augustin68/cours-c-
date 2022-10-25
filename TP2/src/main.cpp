#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"
#include "point.hpp"

int main () {
    std::cout << "COUCOU" << std::endl;

    Rectangle* rect = new Rectangle(1, 2);

    std::cout << "Périmètre rectangle: " << rect->getPerimeter() << std::endl;
    std::cout << "Surface rectangle: " << rect->getSurface() << std::endl;

    Point circleCenter;
    circleCenter.x = 2;
    circleCenter.y = 1;

    Circle* circle = new Circle(circleCenter, 10);

    std::cout << "Périmètre du cercle: " << circle->getPerimeter() << std::endl;

    delete rect;
    delete circle;

    return 0;
}