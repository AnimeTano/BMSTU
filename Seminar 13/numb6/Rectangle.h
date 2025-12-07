#ifndef RECTANGLE_H
#define RECTANGLE_H


#include "Shape.h"
#include <iostream>


class Rectangle : public Shape {
    private:
        double width;

    public:
        Rectangle(double l, double w);

        void displayInfo() const override;

        double calculateArea() const override;
        double calculatePerimeter() const override;

        double getWidth() const { return width; }

        void setWidth(double w) { width = w; }
};

#endif