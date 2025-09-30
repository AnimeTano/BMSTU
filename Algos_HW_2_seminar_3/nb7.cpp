#include <iostream>
#include <vector>
#include <cmath>


const float eps = 1e-9;


bool online(float a[], float b[], float point[]){
    if (point[0] >= std::min(a[0], b[0]) && point[0] <= std::max(a[0], b[0]) &&
        point[1] >= std::min(a[1], b[1]) && point[1] <= std::max(a[1], b[1])){
            float cross = (b[0] - a[0]) * (point[1] - a[1]) - (b[1] - a[1]) * (point[0] - a[0]);
            return abs(cross) < eps;
        }
    return false;
}


bool placement(float cor[][2], float point[], short size){
    short count = 0;

    for (short i = 0; i < size; i++){
        float a[] = {cor[i][0], cor[i][1]};
        float b[] = {cor[(i + 1) % size][0], cor[(i + 1) % size][1]};
        
        if (online(a, b, point)){
            return true;
        }
    }

     for (short i = 0, j = size - 1; i < size; j = i++) {
        float a[] = {cor[j][0], cor[j][1]};
        float b[] = {cor[i][0], cor[i][1]};

        if (((a[1] > point[1]) != (b[1] > point[1])) &&
            (point[0] < (a[0] + (point[1] - a[1]) * (b[0] - a[0]) / (b[1] - a[1])))) {
            count++;
        }
    }

    return count % 2 == 1;
}


int main(){
    short n;
    float coord[100][2], point[2];
    

    std::cout << "Enter amount of vertices:";
    std::cin >> n;

    std::cout << "Enter coordinats of point:";
    std::cin >> point[0] >> point[1];
    
    for (short i = 0; i < n; i++){
        std::cout << "Vertic " << (i + 1) << ":";
        std::cin >> coord[i][0] >> coord[i][1];
    }

    if (placement(coord, point, n)){
        std::cout << "Point is inside";
    } else {
        std::cout << "Point is outside";
    }
    

    return 0;
}