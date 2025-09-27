#include <iostream>
#include <vector>
#include <cmath>


float diag(std::vector <float> x, std::vector <float> y){
    return sqrt(pow((x[1] - x[0]), 2) + pow((y[1] - y[0]), 2));
}

int main(){
    std::vector <float> X;
    std::vector <float> Y;

    std::cout << "Enter coordinats:" << std::endl;
    for (short i = 0; i < 2; i++){
        float x, y;

        std::cout << 'x' << (i + 1) << ":";
        std::cin >> x;
        X.push_back(x);

        std::cout << 'y' << (i + 1) << ":";
        std::cin >> y;
        Y.push_back(y);
    }

    std::cout << "Dist:" << diag(X, Y);

    return 0;
}