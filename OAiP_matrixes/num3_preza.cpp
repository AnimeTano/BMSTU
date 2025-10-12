#include <iostream>


int main(){
    short n = 3;
    int matrix[3][3];
    matrix[0][2] = 1, matrix[1][2] = 1, matrix[2][2] = 1;

    for (short i = 0; i < 3; i++){
        for (short j = 0; j < 2; j++){
            std::cin >> matrix[i][j];
        }
    }

    for (short i = 0; i < 2; i++){
        for (short j = 0; j < 3; j++){
            matrix[n - i - 1][j] -= matrix[0][j];
        }
    }

    float det = (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);

    if (det == 0) {
        std::cout << "Collinear";
    } else {
        std::cout << "Not collinear";
    }

    return 0;
}