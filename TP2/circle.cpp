#include <numbers>

#include "circle.hpp"

int Circle::getCenter() {
    return center;
}

int Circle::getDiameter() {
    return diameter;
}

void Circle::setCenter(int center) {
    this->center = center;
}

void Circle::setDiamteter(int diameter) {
    this->diameter = diameter;
}

double Circle::getPerimeter() {
    return 2 * (std::numbers::pi) * (diameter / 2);
}