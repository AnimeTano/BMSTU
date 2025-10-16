#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>


int main(){
    std::vector<double> fuel;
    fuel.reserve(50);

    /*
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(0.0, 100.0);

    for (short i = 0; i < 50; i++){
        fuel.push_back(dis(gen));
    }
    */

    float x;
    for (short i = 0; i < 50; i++){
        std::cin >> x;

        fuel.push_back(x);
    }

    double *ptr = &fuel[0];

    for (short i = 0; i < fuel.size(); i++){
        std::cout << *(ptr + i) << std::endl;

        if ((i + 1) % 10 == 0){
            std::cout << std::endl;
        }

    }

    auto mnx = std::minmax_element(fuel.begin(), fuel.end(), [](double x, double y){
        return x < y;
    });

    std::cout << "Min:" << *mnx.first << std::endl;
    std::cout << "Max:" << *mnx.second << std::endl;

    double crit_level = *mnx.second * 0.05;
    std::vector<double> crit_levels;

    std::copy_if(fuel.begin(), fuel.end(), back_inserter(crit_levels), [crit_level](double x){
        return x  < crit_level;
    });

    if (crit_levels.size() == 0){
        std::cout << "Always bigger than 5 from max" << std::endl;
    } else std::cout << "Level was lower, than 5%" << std::endl;

    double average = fuel.front() - fuel.back();

    std::cout << "Average consumption:" << average << std::endl;
    
    std::sort(fuel.begin(), fuel.end(), [](double x, double y){
        return x < y;
    });

    std::cout << "Median:" << accumulate(fuel.begin(), fuel.end(), 0.0) / fuel.size() << std::endl; 

    return 0;
}