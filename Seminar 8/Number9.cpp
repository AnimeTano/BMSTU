#include <iostream>
#include <cmath>
#include <iomanip>


double *forward(double **weights, double *inputs, short n, short m){
    double *y = new double[n];

    for (short i = 0; i < n; i++){
        y[i] = 0.0;
        for (short j = 0; j < m; j++){
            y[i] += (weights[i][j] * inputs[j]); 
        }
    }

    return y;
}


void freememory(double **weights, short n){
    for (short i = 0; i < n; i++){
        delete[] weights[i];
    } delete[] weights;
}


void print(double **weights, short n, short m){
    for (short i = 0; i < n; i++){
        for (short j = 0; j < m; j++){
            std::cout << std::fixed << std::setprecision(3) << std::setw(8) <<
             *(*(weights + i) + j) << " ";
        }
        std::cout << "\n";
    }
}


void normalize(double **weights, short n, short m){
    for (short i = 0; i < n; i++){
        double sm = 0.0;

        for (short j = 0; j < m; j++){
            sm += std::abs(weights[i][j]);
        }

        if (sm > 1.0){
            for (short j = 0; j < m; j++){
                weights[i][j] /= sm;
            }
        }

    }
}



int main(){
    short n = 0, m = 0;

    std::cout << "Enter n and m:";
    std::cin >> n >> m;

    double **weights = new double*[n];
    double *inputs = new double[m];

    for (short i = 0; i < n; i++){
        *(weights + i) = new double[m];
    }

    std::cout << "Enter weights(from -1.0 to 1.0):" << "\n";
    for (short i = 0; i < n; i++){
        for (short j = 0; j < m; j++){
            std::cin >> *(*(weights + i) + j);
        }
    }

    std::cout << "Enter inputs:";
    for (short i = 0; i < m; i++){
        std::cin >> *(inputs + i);
    }

    normalize(weights, n, m);
    std::cout << "Normalized weights" << "\n";
    print(weights, n, m);

    double *outputs = forward(weights, inputs, n, m);

    std::cout << "Output:";
    for (short i = 0; i < n; i++){
        std::cout << outputs[i] << " ";
    }

    freememory(weights, n);
    delete[] inputs;
    delete[] outputs;

    return 0;
}