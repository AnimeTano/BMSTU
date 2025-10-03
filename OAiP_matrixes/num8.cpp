#include <iostream>
#include <vector>
#include <cmath>


int main(){
    std::vector <float> X, Y, Z, E;

    std::cout << "It can solve systems of 3 equasions (x, y, z, e) by Cramer method:" << std::endl;
    for (short i = 0; i < 4; i++){
        float num[3];
        
        if (i == 0){
            std::cout << "Enter x-s:";
            std::cin >> num[0] >> num[1] >> num[2];
            for (short j = 0; j < 3; j++){
                X.push_back(num[j]);
            }
        } else if (i == 1){
            std::cout << "Enter y-s:";
            std::cin >> num[0] >> num[1] >> num[2];
            for (short j = 0; j < 3; j++){
                Y.push_back(num[j]);
            }
        } else if(i == 2){
            std::cout << "Enter z-s:";
            std::cin >> num[0] >> num[1] >> num[2];
            for (short j = 0; j < 3; j++){
                Z.push_back(num[j]);
            }
        } else{
            std::cout << "Enter e-s:";
            std::cin >> num[0] >> num[1] >> num[2];
            for (short j = 0; j < 3; j++){
                E.push_back(num[j]);
            }
        }
    }


    float det = (X[0] * Y[1] * Z[2]) + (X[2] * Y[0] * Z[1]) + (X[1] * Y[2] * Z[0]) - (X[2] * Y[1] * Z[0]) - (X[0] * Z[1] * Y[2]) - (X[1] * Y[0] * Z[2]);
    float dx = (E[0] * Y[1] * Z[2]) + (E[2] * Y[0] * Z[1]) + (E[1] * Y[2] * Z[0]) - (E[2] * Y[1] * Z[0]) - (E[0] * Z[1] * Y[2]) - (E[1] * Y[0] * Z[2]);
    float dy = (X[0] * E[1] * Z[2]) + (X[1] * E[2] * Z[0]) + (X[2] * E[0] * Z[1]) - (X[2] * E[1] * Z[0]) - (X[1] * E[0] * Z[2]) - (X[0] * E[2] * Z[1]);
    float dz = (X[0] * Y[1] * E[2]) + (X[2] * Y[0] * E[1]) + (X[1] * Y[2] * E[0]) - (X[2] * Y[1] * E[0]) - (X[0] * E[1] * Y[2]) - (X[1] * Y[0] * E[2]);


    std::cout << "Det:" << det << std::endl;
    std::cout << "Dx:" << dx << std::endl;
    std::cout << "Dy:" << dy << std::endl;
    std::cout << "Dz:" << dz << std::endl;
    
    float arr[3] = {dx / det, dy / det, dz / det};

    for (short i = 0; i < 3; i++){
        std::cout << arr[i] << std::endl;
    }

    return 0;
}