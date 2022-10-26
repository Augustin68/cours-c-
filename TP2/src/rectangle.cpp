#include "rectangle.hpp"

Rectangle::Rectangle(int length, int width) {
    this->length = length;
    this->width = width;
}

Rectangle::~Rectangle(){
    
}

int Rectangle::getLength() {
    return length;
}

int Rectangle::getWidth() {
    return width;
}

void Rectangle::setLength(int length) {
    this->length = length;
}

void Rectangle::setWidth(int width) {
    this->width = width;
}

int Rectangle::getPerimeter() {
    return (width * 2) + (length * 2);
}

int Rectangle::getArea() {
    return length * width;
}

bool Rectangle::hasBiggerPerimeter(Rectangle rectangle) {
    return this->getPerimeter() > rectangle.getPerimeter();
}

bool Rectangle::hasBiggerArea(Rectangle rectangle) {
    return this->getArea() > rectangle.getArea();
}