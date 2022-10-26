#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "point.hpp"

class Rectangle {
    public:
        Rectangle(int length, int width);
        ~Rectangle();
        int getLength();
        int getWidth();
        void setLength(int length);
        void setWidth(int width);
        int getPerimeter();
        int getArea();
        bool hasBiggerPerimeter(Rectangle rectangle);
        bool hasBiggerArea(Rectangle rectangle);

    private:
       int length;
       int width;
       Point topLeftCorner;
};
#endif // RECTANGLE_H