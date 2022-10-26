#include "point.hpp"

#ifndef CIRCLE_H
#define CIRCLE_H
class Circle {
    public:
        Circle(Point center, int diameter);
        ~Circle();
        Point getCenter();
        int getDiameter();
        double getRadius();
        void setCenter(Point center);
        void setDiamteter(int diameter);
        double getPerimeter();
        double getSurface();

        bool isPointOnCircle(Point point);
        bool isPointInCircle(Point point);
    private:
        Point center;
        int diameter;
};
#endif // CIRCLE_H