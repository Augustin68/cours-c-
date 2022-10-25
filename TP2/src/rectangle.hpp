#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "point.hpp"

class Rectangle {
    public:
        /**
         * @brief Construct a new Rectangle object
         * 
         * @param length 
         * @param width 
         */
        Rectangle(int length, int width);

        /**
         * @brief Destroy the Rectangle object
         * 
         */
        ~Rectangle();

        /**
         * @brief Get the Length object
         * 
         * @return int 
         */
        inline int getLength();

        /**
         * @brief Get the Width object
         * 
         * @return int 
         */
        inline int getWidth();

        /**
         * @brief Set the Length object
         * 
         * @param length 
         * @return * void 
         */
        inline void setLength(int length);

        /**
         * @brief Set the Width object
         * 
         * @param width 
         */
        inline void setWidth(int width);

        /**
         * @brief Get the Perimeter object
         * 
         * @return int 
         */
        int getPerimeter();

        /**
         * @brief Get the Surface object
         * 
         * @return int 
         */
        int getSurface();

    private:
       int length;
       int width;
       Point topLeftCorner;
};
#endif // RECTANGLE_H