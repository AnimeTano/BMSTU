#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>


int main(){
    int n = 0;
    std::vector<double> signals;

    std::cout << "Enter size of massive:";
    std::cin >> n;
    signals.resize(n);

    for (short i = 0; i < n; i++){
        std::cin >> signals[i];
    }

    std::unique_ptr<double[]> sign = std::make_unique<double[]>(n);
    std::copy(signals.begin(), signals.end(), sign.get());
    
    double mx = *std::max_element(sign.get(), sign.get() + n);

    auto mean = [&]() -> double {
        return std::accumulate(sign.get(), sign.get() + n, 0.0) / n;
    };

    auto normalize = [&](){
        std::transform(sign.get(), sign.get() + n, sign.get(), [mx](double x){
            return x / mx;
        });
    };

    auto copyBack = [&](){
        std::copy(sign.get(), sign.get() + n, signals.begin());
    };

    double avg = mean();
    normalize();
    copyBack();

    std::cout << std::fixed << std::setprecision(3);
    std::cout << "Average:" << avg << "\n";
    std::cout << "Normalized:" << "\n";

    for (short i = 0; i < signals.size(); i++){
        std::cout << signals[i] << " ";
    }

    return 0;
}