#include <iostream>


class Rectangle {
    private:
        double length;
        double width;
    
    public:
        Rectangle(double l, double w) : length(l), width(w) {}

        double calculateArea() { return width * length; }
        double calculatePerimeter() { return 2 * (width + length); }

        double getLength() { return length; }
        double getWidth() { return width; }

        void setLength(double l) { length = l; }
        void setWidth(double w) { width = w; }

        void displayInfo(){
            std::cout << "Length: " << length << ", width: " << width << ", Area: " << calculateArea() << ", Perimeter: " << calculatePerimeter() << "n";
        }
};


int main(){
    Rectangle rectangle(5.2, 15.5);

    rectangle.displayInfo();

    return 0;
}