#include <iostream>
#include <cmath>
#include <vector>


int main(){
    short n, m;
    int matrix[100][100];
    std::cout << "Enter size of matrix:";
    std::cin >> n >> m;

    std::vector <int> min_row;
    std::vector <int> max_row;
    std::vector <int> min_column;
    std::vector <int> max_column;

    int mxn[2] = {100005000, -1000500};

    for (short i = 0; i < n; i++){
        for (short j = 0; j < m; j++){
            std::cin >> matrix[i][j];

            if (matrix[i][j] > mxn[1]){
                mxn[1] = matrix[i][j];
            }

            if (matrix[i][j] < mxn[0]){
                mxn[0] = matrix[i][j];
            }

        }
        min_row.push_back(mxn[0]);
        max_row.push_back(mxn[1]);
        mxn[0] = 100005000, mxn[1] = -1000500;
    }

    int matr_rev[100][100];
    mxn[0] = 100005000, mxn[1] = -1000500;

    for (short j = 0; j < m; j++){
        for (short i = 0; i < n; i++){
            matr_rev[j][i] = matrix[i][j];

            if (matr_rev[j][i] > mxn[1]){
                mxn[1] = matr_rev[j][i];
            }

            if (matr_rev[j][i] < mxn[0]){
                mxn[0] = matr_rev[j][i];
            }
        }
        min_column.push_back(mxn[0]);
        max_column.push_back(mxn[1]);
        mxn[0] = 100005000, mxn[1] = -1000500;
    }

    bool tf = false;

    for (short i = 0; i < n; i++){
        for (short j = 0; j < m; j++){
            int elem = matrix[i][j];

            if (elem == min_row[i] && elem == max_column[j]){
                std::cout << "A:" << elem << " row:" << (i + 1) << " column:" << (j + 1) << std::endl;
                tf = true;
            }

            if (elem == max_row[i] && elem == min_column[j]){
                std::cout << "B:" << elem << " row:" << (i + 1) << " column:" << (j + 1) << std::endl;
                tf = true;
            }
        }
    }

    if (!tf){
        std::cout << "NONE";
    }

    /*
    std::cout << "---------" << std::endl;
    for (short i = 0; i < n; i++){
        for (short j = 0; j < m; j++){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "---------" << std::endl;
    for (short i = 0; i < m; i++){
        for (short j = 0; j < n; j++){
            std::cout << matr_rev[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (short i = 0; i < min_row.size(); i++){
        std::cout << min_row[i] << " ";
    }

    for (short i = 0; i < max_row.size(); i++){
        std::cout << max_row[i] << " ";
    }

    for (short i = 0; i < min_column.size(); i++){
        std::cout << min_column[i] << " ";
    }

    for (short i = 0; i < max_column.size(); i++){
        std::cout << max_column[i] << " ";
    }
    */

    return 0;
}