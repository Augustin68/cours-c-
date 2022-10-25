#include "point.hpp"

#ifndef CIRCLE_H
#define CIRCLE_H
class Circle {
    public:
        /**
         * @brief Construct a new Circle object
         * 
         */
        Circle(Point center, int diameter);
        /**
         * @brief Destroy the Circle object
         * 
         */
        ~Circle();
        /**
         * @brief Get the Center object
         * 
         * @return Point 
         */
        Point getCenter();

        /**
         * @brief Get the Diameter object
         * 
         * @return int 
         */
        int getDiameter();

        double getRadius();

        /**
         * @brief Set the Center object
         * 
         * @param center 
         */
        void setCenter(Point center);

        /**
         * @brief Set the Diamteter object
         * 
         * @param diameter 
         */
        void setDiamteter(int diameter);


        double getPerimeter();
        double getSurface();

        double distanceFromCenter(Point point);
        bool isPointOnCircle(Point point);
        bool isPointInCircle(Point point);
    private:
        Point center;
        int diameter;
};
#endif // CIRCLE_H