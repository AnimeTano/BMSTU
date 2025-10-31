#include <iostream>
#include <vector>


void analyzePressure(const std::vector<double>& data, double& minval, double& maxval, double& avgval){
    const double* p = data.data();
    short size = data.size();

    double sm = 0.0;

    for (short i = 0; i < size; i++){

        if (*(p + i) < minval) minval = *(p + i);
        if (*(p + i) > maxval) maxval = *(p + i);

        sm += *(p + i);
    }

    avgval = (sm / size);
}

int main(){
    std::vector<double> pressure = {101.3, 100.8, 101.9, 100.5, 102.0};
    double mn = 100500.0, mx = 0.0, mid = 0.0;

    analyzePressure(pressure, mn, mx, mid);

    std::cout << "Min pressure:" << mn << "\n";
    std::cout << "Max pressure:" << mx << "\n";
    std::cout << "Average pressure:" << mid;

    return 0;
}