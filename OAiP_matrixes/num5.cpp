#include <iostream>
#include <cmath>
#include <vector>


int main(){
    short n, m;
    int matrix[100][100];

    std::cout << "Enter shape of matrix:";
    std::cin >> n >> m;

    for (short i = 0; i < n; i++){
        for (short j = 0; j < m; j++){
            std::cin >> matrix[i][j];
        }
    }

    int shape[4] = {0, m - 1, 0, n - 1}; // left, right, up, down 
    
    while (shape[0] <= shape[1] && shape[3] >= shape[2]){
        
        for (int i = shape[0]; i <= shape[1]; i++){
            std::cout << matrix[shape[2]][i] << " ";
        }
        shape[2]++;

        for (short i = shape[2]; i <= shape[3]; i++){
            std::cout << matrix[i][shape[1]] << " ";
        }
        shape[1]--;

        if (shape[2] <= shape[3]){
            for (short i = shape[1]; i >= shape[0]; i--){
                std::cout << matrix[shape[3]][i] << " ";
            }
            shape[3]--;
        }

        if (shape[0] <= shape[1]){
            for (short i = shape[3]; i >= shape[2]; i--){
                std::cout << matrix[i][shape[0]] << " ";
            }
            shape[0]++;
        }
    }

    return 0;
}