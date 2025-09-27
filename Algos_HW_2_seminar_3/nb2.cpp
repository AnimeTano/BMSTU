#include <iostream>
#include <cmath>

int main(){
    float coord[4][2];

    for (short i = 0; i < 4; i++){
        for (short j = 0; j < 2; j++){
            std::cin >> coord[i][j];
        }
    }

    float AB = sqrt(pow((coord[1][0] - coord[0][0]), 2) + pow((coord[1][1] - coord[0][1]), 2));
    float AD = sqrt(pow((coord[3][0] - coord[0][0]), 2) + pow((coord[3][1] - coord[0][1]), 2));
    float BC = sqrt(pow((coord[2][0] - coord[1][0]), 2) + pow((coord[2][1] - coord[1][1]), 2));
    float CD = sqrt(pow((coord[3][0] - coord[2][0]), 2) + pow((coord[3][1] - coord[2][1]), 2));

    std::cout << "Perimetr:" << (AB + AD + BC + CD);

    return 0;
}