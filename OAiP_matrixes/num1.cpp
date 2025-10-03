#include <iostream>
#include <vector>
#include <cmath>


int main(){
    short n;
    int matrix[100][100];

    std::cout << "Enter n:";
    std::cin >> n;

    for (short i = 0; i < n; i++){
        for (short j = 0; j < n; j++){
            std::cin >> matrix[i][j];
        }
    }

    std::cout << "Original:" << std::endl;
    for (short i = 0; i < n; i++){
        for (short j = 0; j < n; j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }


    int matrix_gd[100][100];

    for (short i = 0; i < n; i++){
        for (short j = 0; j < n; j++){
            if (i <= j){
                matrix_gd[i][j] = matrix[j][i];
            } else {
                matrix_gd[i][j] = matrix[j][i];
            }
        }
    }

    std::cout << "Main diag" << std::endl;

    for (short i = 0; i < n; i++){
        for (short j = 0; j < n; j++){
            std::cout << matrix_gd[i][j] << " ";
        }
        std::cout << std::endl;
    }

    int matrix_side[100][100];

    for (short i = 0; i < n; i++){
        for (short j = 0; j < n; j++){
            if (i <= j){
                matrix_side[i][j] = matrix[n - j - 1][n - i - 1];
            } else{
                matrix_side[i][j] = matrix[n - j - 1][n - i - 1];
            }
        }
    }

    std::cout << "Side diag" << std::endl;

    for (short i = 0; i < n; i++){
        for (short j = 0; j < n; j++){
            std::cout << matrix_side[i][j] << " ";
        }
        std::cout << std::endl;
    }

    int matrix_rows[100][100], matrix_vert[100][100];

    if (n % 2 != 0){

        for (short i = 0; i < n; i++){
            for (short j = 0; j < n; j++){
                matrix_vert[i][j] = matrix[i][n - j - 1];
            }
        }

        std::cout << "Rotate column" << std::endl;
        for (short i = 0; i < n; i++){
            for (short j = 0; j < n; j++){
                std::cout << matrix_vert[i][j] << " ";
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "Amount of vertex isn't kr 2" << std::endl;
    }

    if (n % 2 == 0){
        std::cout << "Amount of rows isn't kr 2" << std::endl;
    } else {

        for (short i = 0; i < n; i++){
            for (short j = 0; j < n; j++){
                matrix_rows[i][j] = matrix[n - i - 1][j];
            }
        }

        std::cout << "Rotate rows" << std::endl;
        for (short i = 0; i < n; i++){
            for (short j = 0; j < n; j++){
                std::cout << matrix_rows[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    std::vector<std::pair<int, int>> match;

    bool equal[6] = {1, 1, 1, 1, 1, 1};

    for (short i = 0; i < n; i++){
        for (short j = 0; j < n; j++){
            if (matrix_gd[i][j] != matrix_side[i][j]){
                equal[0] = false;
                break;
            }
        }
    }
    
    if (equal[0])
        match.push_back({1, 2});

    for (short i = 0; i < n; i++){
        for (short j = 0; j < n; j++){
            if (matrix_gd[i][j] != matrix_vert[i][j]){
                equal[1] = false;
                break;
            }
        }
    }

    if (equal[1])
        match.push_back({1, 3});

    for (short i = 0; i < n; i++){
        for (short j = 0; j < n; j++){
            if (matrix_gd[i][j] != matrix_rows[i][j]){
                equal[2] = false;
                break;
            }
        }
    }
    
    if (equal[2])
        match.push_back({1, 4});

    for (short i = 0; i < n; i++){
        for (short j = 0; j < n; j++){
            if (matrix_side[i][j] != matrix_vert[i][j]){
                equal[3] = false;
                break;
            }
        }
    }

    if (equal[3])
        match.push_back({2, 3});

    for (short i = 0; i < n; i++){
        for (short j = 0; j < n; j++){
            if (matrix_side[i][j] != matrix_rows[i][j]){
                equal[4] = false;
                break;
            }
        }
    }

    if (equal[4])
        match.push_back({2, 4});

    for (short i = 0; i < n; i++){
        for (short j = 0; j < n; j++){
            if (matrix_vert[i][j] != matrix_rows[i][j]){
                equal[5] = false;
                break;
            }
        }
    }

    if (equal[5])
        match.push_back({3, 4});

    std::cout << std::endl;
    if (match.size() > 0){
        for (auto x : match){
            std::cout << x.first << " " << x.second << std::endl;
        }
    } else {
        std::cout << "None";
    }

    return 0;
}