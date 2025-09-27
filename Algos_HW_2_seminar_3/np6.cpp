#include <iostream>
#include <vector>
#include <cmath>


const double eps = 1e-9;


//Загуглить можно ли в вектор передовать опред. знач, чтобы не прописывать 6 значений?
short direction(float x0, float x1, float x2, float y0, float y1, float y2){
    if (((x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0)) > 0){
        return 1;
    } else {
        return -1;
    }
}


bool point_on_line(float x0, float x1, float x2, float y0, float y1, float y2){
    if (x2 >= std::min(x0, x1) && y2 >= std::min(y0, y1) && x2 <= std::max(x0, x1) && y2 <= std::max(y0, y1)){
        return (direction(x0, x1, x2, y0, y1, y2)) < eps;
    }
    return false;
}


bool belong(std::vector <float> x, std::vector <float> y){
    float pos[4];
    
    pos[0] = direction(x[0], x[1], x[2], y[0], y[1], y[2]);
    pos[1] = direction(x[0], x[1], x[3], y[0], y[1], y[3]);
    pos[2] = direction(x[2], x[3], x[0], y[2], y[3], y[0]);
    pos[3] = direction(x[2], x[3], x[1], y[2], y[3], y[1]);

    if ((pos[0] * pos[1]) < 0 && (pos[2] != pos[3]) < 0){
        return true;
    }

    if (pos[0] < eps && point_on_line(x[0], x[1], x[2], y[0], y[1], y[2])) return true;
    if (pos[1] < eps && point_on_line(x[0], x[1], x[3], y[0], y[1], y[3])) return true;
    if (pos[2] < eps && point_on_line(x[2], x[3], x[0], y[2], y[3], y[0])) return true;
    if (pos[1] < eps && point_on_line(x[2], x[3], x[1], y[2], y[3], y[1])) return true;

    return false;
}

int main(){
    std::vector <float> X;
    std::vector <float> Y;

    std::cout << "Enter coordinats:" << std::endl;
    for (short i = 0; i < 4; i++){
        float x, y;

        std::cout << 'x' << (i + 1) << ":";
        std::cin >> x;
        X.push_back(x);

        std::cout << 'y' << (i + 1) << ":";
        std::cin >> y;
        Y.push_back(y);
    }

    if (belong(X, Y)){
        std::cout << "Crossing";
    } else {
        std::cout << "Don't cross";
    }

    return 0;
}