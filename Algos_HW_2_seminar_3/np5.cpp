#include <iostream>
#include <cmath>
#include <vector>

int main(){
    std::vector <float> X;
    std::vector <float> Y;

    for (short i = 0; i < 3; i++){
        float x, y;
        std::cout << "Enter x" << (i + 1) << ":";
        std::cin >> x;
        X.push_back(x);

        std::cout << "Enter y" << (i + 1) << ":";
        std::cin >> y;
        Y.push_back(y);
    }

    for (short i = 0; i < 3; i++){
        std::cout << X[i] << std::endl;
        std::cout << Y[i] << std::endl;
    }

    if (((X[1] - X[0]) * (Y[2] - Y[0]) - (X[2] - X[0]) * (Y[1] - Y[0])) == 0){
        std::cout << "At the one line";;
    }
    else{
        std::cout << "Dif lines";
    }
    
    return 0;
}