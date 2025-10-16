#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>


int main(){
    std::vector<float> pressure;
    pressure.reserve(50);
    float x;

    for (short i = 0; i < 50; i++){
        std::cin >> x;

        pressure.push_back(x);
    }

    float *ptr = &pressure[0];
    for (short i = 0; i < pressure.size(); i++){
        std::cout << *(ptr + i) << std::endl;
    }

    pressure.erase(std::remove_if(pressure.begin(), pressure.end(), [](short x){
        return x > 12.0 || x < 0.0;
    }), pressure.end());

    float average = accumulate(pressure.begin(), pressure.end(), 0.0) / pressure.size();

    std::cout << "Average:" << average << std::endl;

    auto mnx = std::minmax_element(pressure.begin(), pressure.end(), [](short x, short y){
        return x < y;
    });

    std::cout << "Min:" << *mnx.first << std::endl;
    std::cout << "Max:" << *mnx.second << std::endl << "\n";


    std::cout << "Elements more than 8 bars" << std::endl;
    for_each(pressure.begin(), pressure.end(), [](float x){
        if (x > 8.0){
            std::cout << x << " bars" << std::endl;
        }
    });    

    return 0;
}