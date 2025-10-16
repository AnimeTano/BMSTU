#include <iostream>
#include <vector>
#include <algorithm>
#include <random>


int main(){
    std::vector<float> consumption;
    std::vector<float> pick;
    consumption.reserve(30);
    float x;

    std::cout << "Enter energy:";
    for (short i = 0; i < 30; i++){
        std::cin >> x;

        consumption.push_back(x);
    }

    float average = accumulate(consumption.begin(), consumption.end(), 0.0) / consumption.size();

    std::cout << "Consumption by month:" << accumulate(consumption.begin(), consumption.end(), 0.0) << std::endl;
    std::cout << "Average consumption:" << average << std::endl;

    auto mnx = std::minmax_element(consumption.begin(), consumption.end(), [](float x, float y){
        return x < y;
    });

    std::cout << "Min:" << *mnx.first << std::endl;
    std::cout << "Max:" << *mnx.second << std::endl;

    std::copy_if(consumption.begin(), consumption.end(), back_inserter(pick), [average](double x){
        return x > (average * 1.2);
    });

    std::cout << "pick consumption * 1.2" << std::endl;
    for (short i = 0; i < pick.size(); i++){
        std::cout << pick[i] << std::endl;
    }

    return 0;
}