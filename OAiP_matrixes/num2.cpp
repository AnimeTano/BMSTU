#include <iostream>
#include <cmath>


int main(){
    int matrix[100][100];
    short n;

    std::cout << "I'll talk only in sum problem" << std::endl;

    std::cout << "Enter size of square matrix:";
    std::cin >> n;

    std::cout << "enter elements of matrix:" << std::endl;
    
    for (short i = 0; i < n; i++){
        for (short j = 0; j < n; j++){
            std::cin >> matrix[i][j];
        }
    }

    float sum[4] = {0, 0, 0, 0}; 
    //строка, столбец, гл диаг, вт диаг
    
    for (short i = 0; i < n; i++){
        for (short j = 0; j < n; j++){
            sum[0] += matrix[i][j];
            sum[1] += matrix[j][i];
        }
    }

    for (short i = 0; i < n; i++){
        sum[2] += matrix[i][i];
    }

    for (short i = 0; i < n; i++){
        sum[3] += matrix[i][n - i - 1];
    }

    sum[0] = ceil(sum[0] / n);
    sum[1] = ceil(sum[1] / n);

    if ((sum[0] == sum[1]) && (sum[2] == sum[3]) && (sum[1] == sum[2]) && (sum[0] == sum[3])){
        std::cout << "Yes" << ", summa:" << sum[0];
    } else {
        std::cout << "No";
    }

    return 0;
}