#include "Rectangle.h"


Rectangle::Rectangle(double l, double w) : Shape(l), width(w) {}


double Rectangle::calculateArea() const { return length * width; }
double Rectangle::calculatePerimeter() const { return 2 * (width + length); }


void Rectangle::displayInfo() const {
    std::cout << "Length: " << length << ", width: " << width << ", area: " << calculateArea() << ", Perimeter: " << calculatePerimeter() << "\n"; 
}