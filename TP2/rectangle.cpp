#include "rectangle.hpp"

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

int Rectangle::getSurface() {
    return length * width;
}