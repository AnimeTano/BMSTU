#ifndef SHAPE_H
#define SHAPE_H


#include <iostream>


class Shape {
    protected:
        double length;

    public:
        Shape(double l) : length(l) {}

        virtual ~Shape() {}
        virtual void displayInfo() const {
            std::cout << "Length: " << length << "\n";
        }
        
        virtual double calculateArea() const { return 0.0; }
        virtual double calculatePerimeter() const { return 0.0; }
        
        double getLength() const { return length; }

        void setLength(double l) { length = l; }
};

#endif