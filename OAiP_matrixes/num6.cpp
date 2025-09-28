#include <iostream>
#include <vector>
#include <cmath>


int main(){
    std::vector <short> first;
    std::vector <short> second;

    std::cout << "It can solve set of 2 equations with (x, y, equl)):" << std::endl;

    for (short i = 0; i < 3; i++){
        short fir, sec;
        if (i == 0){
            std::cout << "enter x-s:";
            std::cin >> fir >> sec;
        } else if(i == 1){
            std::cout << "enter y-s:";
            std::cin >> fir >> sec;
        } else {
            std::cout << "equls-s:";
            std::cin >> fir >> sec;
        }
        first.push_back(fir), second.push_back(sec);
    }

    float det = (first[0] * second[1] - first[1] * second[0]);
    float dx = (first[2] * second[1] - first[1] * second[2]);
    float dy = (first[0] * second[2] - first[2] * second[0]);
    float x = dx / det, y = dy / det;

    std::cout << "x:" << dx << "/" << det << std::endl;
    std::cout << "y:" << dy << "/" << det;

    return 0;
}