#include <iostream>
#include <vector>
#include <algorithm>
#include <random>


int main(){
    std::vector<double> speed;
    std::vector<double> excess;
    speed.reserve(50);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(0.0, 180.0);

    for (short i = 0; i < 50; i++){
        speed.push_back(dis(gen));
    }

    double *ptr = &speed[0];
    for (short i = 0; i < speed.size(); i++){
        std::cout << i + 1 << ":" << *(ptr + i) << std::endl;
    }

    std::sort(speed.begin(), speed.end(), [](double x, double y){
        return x < y;
    });

    std::copy_if(speed.begin(), speed.end(), back_inserter(excess), [](double x){
        return x > 120.0;
    });

    double *ptr1 = &excess[0];
    std::cout << "-------------" << std::endl;

    for (short i = 0; i < excess.size(); i++){
        std::cout << i + 1 << ":" << *(ptr1 + i) << std::endl;
    }

    double average = accumulate(speed.begin(), speed.end(), 0.0) / speed.size();
    std::cout << "Average speed:" << average << std::endl;

    double *ptr2 = &speed[0];
    bool if_there_zero = false;

    for (short i = 0; i < speed.size(); i++){
        if (*(ptr2 + i) == 0.0){
            if_there_zero = true;
            std::cout << "There is one or more zeros";
            break;
        }
    }

    if (!if_there_zero){
        std::cout << "There are no zeros";
    }
    std::cout << "--------" << std::endl;

    short c = 0;
    for (short i = speed.size(); i > 0; i--){
        std::cout << speed.size() - i + 1 << " max:" << speed[i - 1] << std::endl;
        c++;
        if (c == 10){
            break;
        }
    }    

    return 0;
}