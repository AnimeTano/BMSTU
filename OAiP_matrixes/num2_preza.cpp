#include <iostream>
#include <cmath>
using namespace std;
const double PI = 3.1415926535;


int main(){
    double point[2], point_proizv[2];
    float dg;

    cout << "Enter degree:";
    cin >> dg;

    cout << "Enter coord of points:";
    cin >> point[0] >> point[1];

    double theta = (dg * PI / 180.0);
    
    point_proizv[0] = point[0] * cos(theta) + point[1] * sin(theta);
    point_proizv[1] = -point[0] * sin(theta) + point[1] * cos(theta);

    for (short i = 0; i < 2; i++){
        std::cout << point_proizv[i] << std::endl;
    }

    return 0;
}