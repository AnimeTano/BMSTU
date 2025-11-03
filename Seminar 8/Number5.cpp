#include <iostream>


int row(int *row, int columns){
    int summa = 0;
    
    for (short i = 0; i < columns; i++){
        summa += row[i];
    }

    return summa;
}


void sort(int **arr, int n, int m){
    int *sum = new int[n];

    for (short i = 0; i < n; i++){
        sum[i] = row(arr[i], m);
    }

    for (short i = 0; i < (n - 1); i++){
        for (short j = 0; j < (n - i - 1); j++){
            if (sum[j] > sum[j + 1]){
                int *temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                int tmp = sum[j];
                sum[j] = sum[j + 1];
                sum[j + 1] = sum[j];
            }
        }
    }

    delete[] sum;
}


int main(){
    short n, m;

    std::cout << "Enter n amd m:";
    std::cin >> n >> m;

    int **matrix = new int*[n];

    for (short i = 0; i < n; i++){
        matrix[i] = new int[m];
    }

    std::cout << "Enter elements of matrix:" << "\n";
    for (short i = 0; i < n; i++){
        for (short j = 0; j < m; j++){
            std::cin >> *(*(matrix + i) + j);
        }
    }

    std::cout << "Original matrix:" << "\n";
    for (short i = 0; i < n; i++){
        for (short j = 0; j < m; j++){
            std::cout << *(*(matrix + i) + j) << " ";
        }
        std::cout << "\n";
    }

    sort(matrix, n, m);

    std::cout << "Sorted matrix:" << "\n";
    for (short i = 0; i < n; i++){
        for (short j = 0; j < m; j++){
            std::cout << *(*(matrix + i) + j) << " ";
        }
        std::cout << "(" << row(matrix[i], m) << ")";
        std::cout << "\n";
    }

    for (short i = 0; i < n; i++){
        delete[] matrix[i];
    } delete[] matrix;

    return 0;
}