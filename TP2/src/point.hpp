#ifndef POINT_H
#define POINT_H

#include <cmath>

struct Point {
    float x;
    float y;
    float getDistance(Point point) {
        return sqrt(pow(this->x - point.x, 2) + pow(this->y - point.y, 2));
    };
};

#endif // POINT_H