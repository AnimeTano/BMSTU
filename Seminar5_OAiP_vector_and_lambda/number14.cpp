#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>


int main(){
    std::vector<short> consumption;
    std::vector<float> dev(consumption.size()); 
    consumption.reserve(24);
    short x;

    for (short i = 0; i < 24; i++){
        std::cin >> x;

        consumption.push_back(x);
    }

    dev.resize(consumption.size());

    float sum = accumulate(consumption.begin(), consumption.end(), 0.0);
    float average = sum / consumption.size();
    std::cout << "Sum of cons:" << sum << '\n';
    std::cout << "Average:" << sum / consumption.size() << '\n';

    auto mx = max_element(consumption.begin(), consumption.end());
    std::cout << "Max:" << *mx << '\n';

    transform(consumption.begin(), consumption.end(), dev.begin(), [average](int x){
        return x - average;
    });

    std::cout << "Dispersion:" << "\n";
    for (float i : dev){
        std::cout << i << "\n";
    }
    std::cout << "--------" << "\n";

    sort(consumption.begin(), consumption.end(), [](float x, float y){
        return x < y;
    });

    auto *ptr1 = &consumption[0];
    for (short i = 0; i < 5; i++){
        std::cout << *(ptr1 + i) << std::endl;
    }
    
    return 0;
}