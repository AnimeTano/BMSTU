#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>


int main(){
    std::vector<float> vibr;
    vibr.reserve(50);
    float x;

    std::cout << "Enter vibrations:";
    for (short i = 0; i < 50; i++){
        std::cin >> x;

        vibr.push_back(x);
    }

    vibr.erase(std::remove_if(vibr.begin(), vibr.end(), [](float x){
        return x < 0.1;
    }), vibr.end());

    std::sort(vibr.begin(), vibr.end(), [](float x, float y){
        return x < y;
    });

    for (short i = 0; i < vibr.size(); i++){
        std::cout << vibr[i] << " ";
    }

    std::cout << "Average:" << accumulate(vibr.begin(), vibr.end(), 0.0) / vibr.size() << std::endl;
    std::cout << "Max:" << vibr[vibr.size() - 1] << std::endl;

    bool ok = true;
    float *ptr = &vibr[0];

    for (short i = 0; i < vibr.size(); i++){
        if (*(ptr + i) <= 0.5){
            ok = false;
            break;
        }
    }

    if (ok){
        std::cout << "All elements more than 0.5" << std::endl;
    } else {
        std::cout << "Not all elements more than 0.5" << std::endl;
    }

    short cnt = 0;

    for (short i = vibr.size() - 1; i > 0; i--){
        std::cout << (vibr.size() - i) << ":" << vibr[i] << std::endl;
        cnt++;

        if (cnt == 10) break;
    }

    return 0;
}