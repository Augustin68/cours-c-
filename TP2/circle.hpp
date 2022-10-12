#ifndef CIRCLE_H
#define CIRCLE_H
class Circle {
    public:
        /**
         * @brief Get the Center object
         * 
         * @return int 
         */
        int getCenter();

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
        void setCenter(int center);

        /**
         * @brief Set the Diamteter object
         * 
         * @param diameter 
         */
        void setDiamteter(int diameter);


        double getPerimeter();
        int getSurface();
    private:
        int center;
        int diameter;
};
#endif // CIRCLE_H