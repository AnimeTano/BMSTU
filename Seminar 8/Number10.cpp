#include <iostream>
#include <cmath>


double *averageLoadPerNode(int **load, int n, int t){
    double *matrix = new double[n];

    for (short i = 0; i < n; i++){
        double sm = 0.0;
        for (short j = 0; j < t; j++){
            sm += *(*(load + i) + j);
        }
        matrix[i] = (sm / t);
    }

    return matrix;
}


void normalizeLoad(int **load, int n, int t){
    double *avr = averageLoadPerNode(load, n, t);
    
    for (short i = 0; i < n; i++){
        for (short j = 0; j < t; j++){
            int ld = *(*(load + i) + j);
            if (ld > 80){
                int tenproc = std::round(ld * 0.1);

                *(*(load + i) + j) = (ld - tenproc);

                int another = (n - 1);
                if (another > 0){
                    int b = tenproc / another, rem = tenproc % another;

                    for (short k = 0; k < n; k++){
                        if (k != i){
                            int add = b;
                            if (rem > 0){
                                add++;
                                rem--;
                            }
                            *(*(load + k) + j) += add;

                            if (*(*(load + k) + j) > 100) *(*(load + k) + j) = 100;
                        }
                    }
                }
            }
        }
    }
}


int findCriticalInterval(int **load, int n, int t){
    int sm = 0, crit = 0;

    for (short i = 0; i < t; i++){
        int s = 0;
        for (short j = 0; j < n; j++){
            s += *(*(load + j) + i);
        }

        if (s > sm){
            sm = s;
            crit = i;
        }
    }

    return crit;
}


void printmatrix(int **load, short n, short t){
    for (short i = 0; i < n; i++){
        for (short j = 0; j < t; j++){
            std::cout << *(*(load + i) + j) << " ";
        }
        std::cout << "\n";
    }
}


int main(){
    int n, t;

    std::cout << "Enter amount of Nodes and Intervals:";
    std::cin >> n >> t;

    int **load = new int*[n];

    for (short i = 0; i < n; i++){
        load[i] = new int[t];
    }

    std::cout << "Enter elemets of matrix:\n";
    for (short i = 0; i < n; i++){
        for (short j = 0; j < t; j++){
            std::cin >> *(*(load + i) + j);
        }
    }

    double *avg = averageLoadPerNode(load, n, t);
    std::cout << "Average:\n";
    for (short i = 0; i < n; i++){
        std::cout << avg[i] << " ";
    } 

    normalizeLoad(load, n, t);

    std::cout << "\nNormalized matrix:\n";
    printmatrix(load, n, t);

    int crit = findCriticalInterval(load, n, t);
    int sm = 0;

    for (short i = 0; i < n; i++){
        sm += *(*(load + i) + crit);
    }

    std::cout << "Critical:" << crit << "\n";
    std::cout << "Sum:" << sm;

    for (short i = 0; i < n; i++){
        delete[] load[i];
    } delete[] load;
    delete[] avg;

    return 0;
}