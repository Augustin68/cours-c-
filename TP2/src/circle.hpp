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
        int getSurface();
    private:
        Point center;
        int diameter;
};
#endif // CIRCLE_H