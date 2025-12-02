#include <iostream>
#include <cmath>


const double PI = 3.14159265358979323846;


struct Rectangle {
    double length;
    double width;
};


union SD {
    double radius;         
    Rectangle rectangle;
};


enum Type {
    CIRCLE,
    RECTANGLE
};


struct Shape {
    Type type;   
    SD data;   
};


void setCircle(Shape& shape, double radius) {
    shape.type = CIRCLE;
    shape.data.radius = radius;
}


void setRectangle(Shape& shape, double length, double width) {
    shape.type = RECTANGLE;
    shape.data.rectangle.length = length;
    shape.data.rectangle.width = width;
}


double Area(const Shape& shape) {
    switch (shape.type) {
        case (CIRCLE):
            return PI * shape.data.radius * shape.data.radius;
        case (RECTANGLE):
            return shape.data.rectangle.length * shape.data.rectangle.width;
        default:
            return 0;
    }
}


void printShapeInfo(const Shape& shape) {
    switch (shape.type) {
        case (CIRCLE):
            std::cout << "Circle radius: " << shape.data.radius << std::endl;
            break;
        case (RECTANGLE):
            std::cout << "Rectangles length: " << shape.data.rectangle.length << ", width: " << shape.data.rectangle.width << std::endl;
            break;
    }
}


int main() {
    Shape shape;
    short n = 0;
    
    std::cout << "Enter (1 - circle, 2 - rectangle): ";
    std::cin >> n;
    
    if (n == 1) {
        double radius = 0.0;
        std::cout << "Enter circle radius: ";
        std::cin >> radius;
        
        setCircle(shape, radius);
        printShapeInfo(shape);
        std::cout << "Area of circle: " << Area(shape) << "\n";
        
    } else if (n == 2) {
        double length = 0.0, width = 0.0;
        std::cout << "Enter length: ";
        std::cin >> length;
        std::cout << "Enter width: ";
        std::cin >> width;
        
        setRectangle(shape, length, width);
        printShapeInfo(shape);
        std::cout << "Area of rect: " << Area(shape) << "\n";        
    }
    
    return 0;
}