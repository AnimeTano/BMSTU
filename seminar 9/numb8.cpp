#include <iostream>
#include <memory>


double average(std::unique_ptr<double[]>& arr, short n){
    double sm = 0.0;
    for (short i = 0; i < n; i++){
        sm += arr[i];
    }
    return (sm / n);
}

int main(){
    short n = 0, m = 0, k = 0;
    std::cout << "Enter amount of elements for every massive:";
    std::cin >> n >> m >> k;

    std::unique_ptr<double[]> temp = std::make_unique<double[]>(n);
    std::unique_ptr<double[]> pres = std::make_unique<double[]>(m);
    std::unique_ptr<double[]> humid = std::make_unique<double[]>(k);

    std::cout << "Enter elements of massive temperature:";
    for (short i = 0; i < n; i++){
        std::cin >> temp[i];
    }

    std::cout << "Enter elements of massive pressure:";
    for (short i = 0; i < m; i++){
        std::cin >> pres[i];
    }

    std::cout << "Enter elements of massive humidities:";
    for (short i = 0; i < k; i++){
        std::cin >> humid[i];
    }

    std::cout << "Average temperature: " << average(temp, n) << "\n";
    std::cout << "Average pressure: " << average(pres, n) << "\n";
    std::cout << "Average humidities: " << average(humid, n);

    return 0;
}