#include <iostream>

// S of triangle
int main(){
    float X[3];
    float Y[3];

    std::cout << "Enter coord:" << std::endl;

    for (short i = 0; i < 3; i++){
        std::cout << "x" << i + 1 << ':';
        std::cin >> X[i];
        
        std::cout << "y" << i + 1 << ':';
        std::cin >> Y[i];
    }

    for (short i = 0; i < 3; i++){
        std::cout << X[i] << std::endl;
        std::cout << Y[i] << std::endl;
    }

    float S = 0.5 * abs(X[0] * (Y[1] - Y[2]) + X[1] * (Y[2] - Y[0]) + X[2] * (Y[0] - Y[1]));
    std::cout << "S = " << S;

    return 0;
}