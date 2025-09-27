#include <iostream>


int main(){
    float X[3];
    float Y[3];

    std::cout << "Enter coordinats:" << std::endl;

    for (short i = 0; i < 3; i++){
        std::cout << "Enter x" << (i + 1) << std::endl;
        std::cin >> X[i];

        std::cout << "Enter y" << (i + 1) << std::endl;
        std::cin >> Y[i];
    }

    float cx = ((X[0] + X[1] + X[2]) / 3.0);
    float cy = ((Y[0] + Y[1] + Y[2]) / 3.0);

    std::cout << "Cx:" << cx << std::endl;
    std::cout << "Cy:" << cy << std::endl;

    return 0;
}