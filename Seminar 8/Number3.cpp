#include <iostream>


void free2D(int **arr, int n){
    
    for (short i = 0; i < n; i++){
        delete[] arr[i];
    }
    delete[] arr;

}

int main(){
    short n, m;

    std::cout << "Enter size of matrix(rows, columns):";
    std::cin >> n >> m;

    int **matrix = new int*[n];

    for (short i = 0; i < n; i++){
        matrix[i] = new int[m];
    }

    std::cout << "Enter elements of matrix:" << "\n";
    for (short i = 0; i < n; i++){
        for (short j = 0; j < m; j++){
            std::cin >> matrix[i][j];
        }
    }

    std::cout << "Elements:" << "\n";
    for (short i = 0; i < n; i++){
        for (short j = 0; j < m; j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
    
    free2D(matrix, n);

    return 0;
}