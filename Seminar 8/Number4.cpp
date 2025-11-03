#include <iostream>


int **transpose(int **matrix, int n, int m){
    int **matrix_transpose = new int*[m];

    for (short i = 0; i < m; i++){
        matrix_transpose[i] = new int[n];
    }

    for (short i = 0; i < n; i++){
        for (short j = 0; j < m; j++){
            matrix_transpose[j][i] = matrix[i][j];
        }
    }

    return matrix_transpose;
}


int main(){
    short n, m;

    std::cout << "Enter n and m:";
    std::cin >> n >> m;

    int **matrix = new int*[n];

    for (short i = 0; i < n; i++){
        matrix[i] = new int[m];
    }

    for (short i = 0; i < n; i++){
        for (short j = 0; j < m; j++){
            std::cin >> matrix[i][j];
        }
    }

    std::cout << "Matrix:" << "\n";

     for (short i = 0; i < n; i++){
        for (short j = 0; j < m; j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
    
    int **matrix_transpose = transpose(matrix, n, m);

    std::cout << "Matrix transpose:" << "\n";
    for (short i = 0; i < m; i++){
        for (short j = 0; j < n; j++){
            std::cout << matrix_transpose[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}