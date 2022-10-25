#include <cmath>
#include <iostream>

#include "circle.hpp"
#include "point.hpp"

# define M_PI 3.14159265358979323846

Circle::Circle(Point center, int diameter) {
    this->center = center;
    this->diameter = diameter;
}

Circle::~Circle() {}

Point Circle::getCenter() {
    return center;
}

int Circle::getDiameter() {
    return diameter;
}

double Circle::getRadius() {
    return diameter / 2;
}

void Circle::setCenter(Point center) {
    this->center = center;
}

void Circle::setDiamteter(int diameter) {
    this->diameter = diameter;
}

double Circle::getPerimeter() {
    return 2 * M_PI * this->getRadius();
}

double Circle::getSurface() {
    return M_PI * pow(this->getRadius(), 2);
}

double Circle::distanceFromCenter(Point point) {
    return sqrt(pow(this->center.x - point.x, 2) + pow(this->center.y - point.y, 2));
}

bool Circle::isPointInCircle(Point point) {    
    if(this->distanceFromCenter(point) < this->getRadius()) {
        return true;
    }
    return false;
}

bool Circle::isPointOnCircle(Point point) {
    if(this->distanceFromCenter(point) == this->getRadius()){
        return true;
    }
    return false;
}