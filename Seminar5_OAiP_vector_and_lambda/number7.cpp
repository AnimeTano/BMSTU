#include <iostream>
#include <vector>
#include <algorithm>
#include <random>


int main(){
    std::vector<double> temp;
    temp.reserve(25);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(-75.0, 75.0);

    for (short i = 0; i < 25; i++){
        temp.push_back(dis(gen));
    }
    
    temp.erase(std::remove_if(temp.begin(), temp.end(), [](int x){
        return x > 50.0 || x < -50.0;
    }), temp.end());

    
    std::sort(temp.begin(), temp.end(), [](double x, double y){
        return x < y;
    });

    double *ptr = &temp[0];

    for (short i = 0; i < temp.size(); i++){
        std::cout << i + 1 << ":" << *(ptr + i) << std::endl;
    }

    short size = temp.size();

    std::cout << "Min:" << temp[0] << std::endl;
    std::cout << "Middle:" << temp[temp.size() / 2 - 1] << std::endl;
    std::cout << "Max:" << temp[size - 1] << std::endl;
    
    bool more_than_min10 = true;

    for (short i = 0; i < temp.size(); i++){
        if (*(ptr + i) < -10.0){
            more_than_min10 = false;
            std::cout << "False";
            break;
        }
    }

    return 0;
}