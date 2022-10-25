#include <numbers>

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

void Circle::setCenter(Point center) {
    this->center = center;
}

void Circle::setDiamteter(int diameter) {
    this->diameter = diameter;
}

double Circle::getPerimeter() {
    return 2 * M_PI * (diameter / 2);
}
