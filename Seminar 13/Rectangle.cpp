#include "Rectangle.h"
#include <iostream>


Rectangle::Rectangle(double l, double w) : length(l), width(w) {}


double Rectangle::calculateArea() { return width * length; }
double Rectangle::calculatePerimeter() { return 2 * (width + length); }


void Rectangle::displayInfo() {
    std::cout << "Length: " << length << ", width: " << width << ", Area: " << calculateArea() << ", Perimeter: " << calculatePerimeter() << "n";
}