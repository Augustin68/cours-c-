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
    circleCenter.x = 0;
    circleCenter.y = 0;

    Circle* circle = new Circle(circleCenter, 10);

    std::cout << "Périmètre du cercle: " << circle->getPerimeter() << std::endl;
    std::cout << "Surface du cercle: " << circle->getSurface() << std::endl;

    Point pointA;
    pointA.x = 0;
    pointA.y = 5;

    std::cout << "Est ce que Point A est SUR le cercle ? (oui) :" << circle->isPointOnCircle(pointA) << std::endl; 
    std::cout << "Est ce que Point A est DANS le cercle ? (non) :" << circle->isPointInCircle(pointA) << std::endl; 

    delete rect;
    delete circle;

    return 0;
}