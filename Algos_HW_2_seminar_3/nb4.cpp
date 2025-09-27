#include <iostream>
#include <cmath>

int main(){
    float X[4];
    float Y[4];

    for (short i = 0; i < 4; i++){
        std::cout << "Enter x" << (i + 1) << ":";
        std::cin >> X[i];

        std::cout << "Enter y" << (i + 1) << ":";
        std::cin >> Y[i];
    }

    float AB = sqrt(pow((X[1] - X[0]), 2) + pow(Y[1] - Y[0], 2));
    float AD = sqrt(pow((X[3] - X[0]), 2) + pow(Y[3] - Y[0], 2));

    float BC = sqrt(pow((X[2] - Y[1]), 2) + pow((X[2] - Y[1]), 2));
    float CD = sqrt(pow((X[3] - Y[2]), 2) + pow((X[3] - Y[2]), 2));

    std::cout << "Diagonal from AB to AD:" << sqrt(pow(AB, 2) + pow(AD, 2)) << std::endl;
    std::cout << "Diagonal from BC to CD:" << sqrt(pow(BC, 2) + pow(CD, 2));


    return 0;
}