#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"
#include "point.hpp"

int main () {
    std::cout << "====== RECTANGLE ======" << std::endl;

    Rectangle* rect = new Rectangle(1, 2);

    std::cout << "Périmètre rectangle: " << rect->getPerimeter() << std::endl;
    std::cout << "Surface rectangle: " << rect->getSurface() << std::endl;

    Point circleCenter;
    circleCenter.x = 0;
    circleCenter.y = 0;

    std::cout << "====== CIRCLE ======" << std::endl;

    Circle* circle = new Circle(circleCenter, 10);

    std::cout << "Périmètre du cercle: " << circle->getPerimeter() << std::endl;
    std::cout << "Surface du cercle: " << circle->getSurface() << std::endl;

    Point pointA;
    pointA.x = 0;
    pointA.y = 5;

    std::cout << "Est ce que Point A est SUR le cercle ? (should be true) :" << circle->isPointOnCircle(pointA) << std::endl; 
    std::cout << "Est ce que Point A est DANS le cercle ? (should be false) :" << circle->isPointInCircle(pointA) << std::endl; 

    std::cout << "====== TRIANGLE ======" << std::endl;

    Point pointB;
    pointB.x = 5;
    pointB.y = 5;

    Point pointC;
    pointC.x = 0;
    pointC.y = 0;
    Triangle* triangle = new Triangle(pointA, pointB, pointC);

    std::cout << "Longueurs des 3 côtés du triangle: " << std::endl;
    std::array<float, 3> lengths = triangle->getSideLengths();
    for(int i = 0; i<3; i++){
        std::cout << "Longueur côté " << i+1 << ":" << lengths[i] << std::endl;
    }

    std::cout <<"Longueur de la base du triangle: " << triangle->getBase() << std::endl;

    std::cout << "Surface du triangle: " << triangle->getArea() << std::endl;

    std::cout << "Hauteur du triangle: " << triangle->getHeight() << std::endl;

    delete rect;
    delete circle;
    delete triangle;

    return 0;
}