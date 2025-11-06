#include <iostream>
#include <iomanip>


void print(double **arr, short n, short m){
    for (short i = 0; i < n; i++){
        for (short j = 0; j < m; j++){
            std::cout << std::fixed << std::setprecision(2) << std::setw(5) <<
             *(*(arr + i) + j) << " ";
        }std::cout << "\n";
    }
}


void freememory(double **arr, short n){
    for (short i = 0; i < n; i++){
        delete[] arr[i];
    } delete[] arr;
}


double **allocatePlate(int n, int m){
    double **plate = new double*[n];
    
    for (short i = 0; i < n; i++){
        *(plate + i) = new double[m];
    }

    return plate;
}


void updateTemperature(double **plate, int n, int m){
    double **temp = allocatePlate(n, m);

    for (short i = 0; i < n; i++){
        for (short j = 0; j < m; j++){
            temp[i][j] = plate[i][j];
        }
    }

    for (short i = 1; i < (n - 1); i++){
        for (short j = 1; j < (m - 1); j++){
            if (i == (n / 2) && j == (m / 2)){
                continue;
            }
            
            double sm = plate[i + 1][j] + plate[i - 1][j] + 
            plate[i][j + 1] + plate[i][j - 1];
            temp[i][j] = sm / 4.0;
        }
    }

    for (short i = 0; i < n; i++){
        for (short j = 0; j < m; j++){
            plate[i][j] = temp[i][j];
        }
    }
    
    freememory(temp, n);
}


int main(){
    short n = 0, m = 0, k = 0;

    std::cout << "Enter n and m:";
    std::cin >> n >> m;

    std::cout << "Enter amount of iterations:";
    std::cin >> k;

    double **plate = allocatePlate(n, m);

    for (short i = 0; i < n; i++){
        for (short j = 0; j < m; j++){
            plate[i][j] = 20.0;
        }
    } plate[n / 2][m / 2] = 100.0;

    std::cout << "Original plate:" << "\n";
    print(plate, n, m);

    for (short i = 0; i < k; i++){
        updateTemperature(plate, n, m);
    }

    std::cout << k << " iterations:" << "\n";
    print(plate, n, m);

    freememory(plate, n);

    return 0;
}