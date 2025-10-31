#include <iostream>
#include <string>
#include <vector>
#include <cmath>

double computeRMS(const std::vector<double>& signal){
    const double* p = signal.data();
    double rms = 0;

    for (short i = 0; i < signal.size(); i++){
        rms += pow(*(p + i), 2);
    }

    rms = sqrt(rms / (signal.size()));

    return rms;
}


int main(){
    std::vector<double> signal = {2.0, 3.0, 1.0, 4.0, 3.0};

    std::cout << "RMS:" << computeRMS(signal);

    return 0;
}