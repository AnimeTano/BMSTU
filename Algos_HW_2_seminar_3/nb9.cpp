#include <iostream>
#include <vector>
#include <cmath>


const double eps = 1e-9;


float direction(float x0, float y0, float x1, float y1, float x2, float y2){
    float cp = (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);
    if (abs(cp) < eps){
        return 0;
    } else if(cp > 0){
        return 1;
    } else {
        return -1;
    }
}


bool point_on_line(float x0, float y0, float x1, float y1, float x2, float y2){
    if (direction(x0, y0, x1, y1, x2, y2) > eps){
        return 0;
    }

    if (x2 >= std::min(x0, x1) && x2 <= std::max(x0, x1) &&
        y2 >= std::min(y0, y1) && y2 <= std::max(y0, y1)){
            return 1;
    }
    return 0;
}


bool belong(float x1, float y1, float x2, float y2,
    float x3, float y3, float x4, float y4){
    float pos[4];
    
    pos[0] = direction(x1, y1, x2, y2, x3, y3);
    pos[1] = direction(x1, y1, x2, y2, x4, y4);
    pos[2] = direction(x3, y3, x4, y4, x1, y1);
    pos[3] = direction(x3, y3, x4, y4, x2, y2);

    if ((pos[0] * pos[1]) < 0 && (pos[2] != pos[3]) < 0){
        return true;
    }

    if (pos[0] < eps && point_on_line(x1, y1, x2, y2, x3, y3)) return true;
    if (pos[1] < eps && point_on_line(x1, y1, x2, y2, x4, y4)) return true;
    if (pos[2] < eps && point_on_line(x3, y3, x4, y4, x1, y1)) return true;
    if (pos[3] < eps && point_on_line(x3, y3, x4, y4, x2, y2)) return true;

    return false;
}


bool intersection(std::vector <float> x, std::vector <float> y, float px, float py, short size){
    bool inside = false;

    for (short i = 0, j = (size - 1); i < size; j = i++){
        float x_i = x[i], y_i = y[i];
        float x_j = x[j], y_j = y[j];

        if (abs(x_i - px) < eps && abs(y_i - py) < eps){
            return true;
        }

        if (point_on_line(x_i, y_i, x_j, y_j, px, py)){
            return true;
        }

        if (((y_i > py) != (y_j > py)) &&
            (px < (x_j - x_i) * (py - y_i) / (y_j - y_i) + x_i)){
                inside = true;
        }
    }

    return inside;
}


bool inter(std::vector <float> x1, std::vector <float> y1,
std::vector <float> x2, std::vector <float> y2, short size_1, short size_2){

    for (short i = 0; i < size_1; i++){
        float X1 = x1[i], Y1 = y1[i];
        float X1_i = x1[(i + 1) % size_1], Y1_i = y1[(i + 1) % size_1];
        
        for (short j = 0; j < size_2; j++){
            float X2 = x2[j], Y2 = y2[j];
            float X2_j = x2[(j + 1) % size_2], Y2_j = y2[(j + 1) % size_2];
            
            if (belong(X1, Y1, X1_i, Y1_i, X2, Y2, X2_j, Y2_j)){
                return true;
            }
        }
    }

    for (short i = 0; i < size_1; i++){
        if (intersection(x2, y2, x1[i], y1[i], size_2)){
            return true;
        }
    }
    return 0;
}



int main(){
    short n[2];
    std::vector <float> X_1, Y_1, X_2, Y_2;

    for (short i = 0; i < 2; i++){
        std::cout << "Enter amount of vercles for " << (i + 1) << "mgl:";
        std::cin >> n[i];
    }

    if (n[0] < 3 || n[1] < 3){
        std::cout << "We nust have more than verticles";
        return 1;
    }

    std::cout << "Enter coord of first mgl:" << std::endl;;
    for (short i = 0; i < n[0]; i++){
        float x, y;
        std::cout << "Enter coord(x and y):";
        std::cin >> x >> y;

        X_1.push_back(x), Y_1.push_back(y);
    }

    std::cout << "Enter coord of second mgl:" << std::endl;
    for (short j = 0; j < n[1]; j++){
        float t1, t2;
        std::cout << "Enter coord(x and y):";
        std::cin >> t1 >> t2;

        X_2.push_back(t1), Y_2.push_back(t2);
    }

    if (inter(X_1, Y_1, X_2, Y_2, n[0], n[1])){
        std::cout << "Mgl peresek.";
    } else {
        std::cout << "Mgl ne peresek.";
    }

    return 0;
}