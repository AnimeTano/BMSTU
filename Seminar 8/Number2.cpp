#include <iostream>


int main(){
    short n = 0, m = 0;

    std::cout << "Size of matrix(row and columns):";
    std::cin >> n >> m;

    int **arr = new int*[n];
    
    for (short i = 0; i < n; i++){
        arr[i] = new int[m];
    }

    for (short i = 0; i < n; i++){
        for (short j = 0; j < m; j++){
            std::cin >> arr[i][j];
        }
    }

    for (short i = 0; i < n; i++){
        for (short j = 0; j < m; j++){
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}