#include <iostream>

int main(){
    int number;

    std::cout << "Enter number:";
    std::cin >> number;

    if (number > 0){
        std::cout << "Pos";
    }
    else if (number < 0){
        std::cout << "Neg";
    }
    else {
        std::cout << "0";
    }

    return 0;
}