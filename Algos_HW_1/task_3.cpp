#include <iostream>
#include <cmath>


int main(){
    double h, v0, dg, alp, time, dt;
    const float g = 9.81;
    const float pi = 3.1415;
    double coord[2] = {0.0, 0.0}; // x, y
    short type;
    std::string type_of_movement[3] = {"1:Uniform linear motion", "2:Free fall", "3:Vertical projectile motion"};

    for (short i = 0; i < 3; i++){
        std::cout << type_of_movement[i] << std::endl;
    }

    std::cout << "Select type of movement and enter number:";
    std::cin >> type;

    std::cout << "Enter step of time:" << std::endl;
    std::cin >> dt;

    std::cout << "Enter h:" << std::endl;
    std::cin >> h;

    std::cout << "Enter v0:" << std::endl;
    std::cin >> v0;

    std::cout << "Enter dg:" << std::endl;
    std::cin >> dg;

    std::cout << "Enter alp:" << std::endl;
    std::cin >> alp;

    std::cout << "Enter time:" << std::endl;
    std::cin >> time;

    std::cout << "Enter coord(x until y):" << std::endl;
    for (short i = 0; i < 2; i++){
        std::cin >> coord[i]; 
    }

    double radian = dg * pi / 180.0;
    
    switch(type){
        case 1:
            for (float i = 0; i < time; i += dt){
                std::cout << "x at " << i << " is:" << (coord[0] + v0 * i) << std::endl;
            }
            break;
        case 2:
            for (float i = 0; i < time; i += dt){
                std::cout << "y at " << i << " is:" << (h - 0.5*g*i*i) << std::endl;
            }
            break;
        case 3:
            for (float i = 0; i < time; i += dt){
            std::cout << "y at " << i << " is:" << (h + v0 * sin(radian) * i - 0.5 * g * i * i) << std::endl;
            }
        default:
            std::cout << "Nothing";
            break;
    }


    return 0;
}