#include <array>
#include <cmath>

#include "triangle.hpp"
#include "point.hpp"

// Constructeur
Triangle::Triangle(Point pointA, Point pointB, Point pointC) {
    this->pointA = pointA;
    this->pointB = pointB;
    this->pointC = pointC;
}

// Destructeur
Triangle::~Triangle(){}

std::array<float, 3> Triangle::getSideLengths()
{
    std::array<float, 3> lengths;

    lengths[0] = this->pointA.getDistance(this->pointB);
    lengths[1] = this->pointB.getDistance(this->pointC);
    lengths[2] = this->pointC.getDistance(this->pointA);

    return lengths;
} 

float Triangle::getBase()
{
    std::array<float, 3> lengths = this->getSideLengths();
    float maxLength = lengths[0];
    for(int i = 0; i < 3; i++) {
        if (lengths[i] > maxLength) {
            maxLength = lengths[i];
        }
    }
    return maxLength;
}

float Triangle::getArea() 
{
    std::array<float, 3> lengths = this->getSideLengths();

    // Using heron formula
    float halfPerimeter = (lengths[0] + lengths[1] + lengths[2]) / 2;

    return sqrt(halfPerimeter * (halfPerimeter - lengths[0]) * (halfPerimeter - lengths[1]) * (halfPerimeter - lengths[2]));
}

float Triangle::getHeight()
{
    return 2 * this->getArea() / this->getBase();
}
