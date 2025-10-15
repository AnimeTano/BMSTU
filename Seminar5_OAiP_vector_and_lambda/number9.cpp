#include <iostream>
#include <vector>
#include <algorithm>
#include <random>


int main(){
    std::vector<float> power;
    power.reserve(20);
    float x = 0;

    std::cout << "Enter power:" << std::endl;

    for (short i = 0; i < 20; i++){
        std::cin >> x;

        power.push_back(x);
    }

    power.erase(std::remove_if(power.begin(), power.end(), [](float x){
        return x <= 0.0;
    }), power.end());

    std::sort(power.begin(), power.end(), [](float x, float y){
        return x < y;
    });

    float *ptr = &power[0];

    std::cout << "Del power < 0" << std::endl;
    for (short i = 0; i < power.size(); i++){
        std::cout << i + 1 << ":" << *(ptr + i) << std::endl;
    }

    std::cout << "Min:" << power[0] << std::endl;
    std::cout << "Average:" << accumulate(power.begin(), power.end(), 0.0) / power.size() << std::endl;
    std::cout << "Max:" << power[power.size() - 1] << std::endl;

    bool ok = true;
    float *ptr1 = &power[0];

    for (short i = 0; i < power.size(); i++){
        if (*(ptr1 + i) > 90.0 || *(ptr1 + i) < 10.0){
            ok = false;
            break;
        }
    }
    if (!ok){
        std::cout << "Worked not in range from 10 to 90" << std::endl;
    } else {
        std::cout << "Worked in range from 10 to 90" << std::endl;
    }


    std::cout << "Medianna:" << accumulate(power.begin(), power.end(), 0.0) / power.size();

    return 0;
}