#include <iostream>


int sumElements(int **arr, int n, int m){
    int summa = 0;

    for (short i = 0; i < n; i++){
        for (short j = 0; j < m; j++){
            summa += *(*(arr + i) + j);
        }
    }

    return summa;
}


int main(){
    short n, m;

    std::cout << "Enter n amd m:";
    std::cin >> n >> m;

    int **matrix = new int*[n];

    for (short i = 0; i < n; i++){
        *(matrix + i) = new int[m];
    }

    std::cout << "Enter elements of matrix:" << "\n";
    for (short i = 0; i < n; i++){
        for (short j = 0; j < m; j++){
            std::cin >> *(*(matrix + i) + j);
        }
    }

    std::cout << "Sum:" << sumElements(matrix, n, m);

    return 0;
}