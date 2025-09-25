#include <iostream>


int main(){
    int num[3] = {0, 0, 0};
    char a;

    std::cout << "Enter first element:" << std::endl;
    std::cin >> num[0];

    std::cout << "Enter second element:" << std::endl;
    std::cin >> num[1];

    std::cout << "Enter char(+, *, /, -):" << std::endl;
    std::cin >> a;

    switch(a){
        case '+':
            num[2] = num[1] + num[0];
            break;
        case '-':
            num[2] = num[1] - num[0];
            break;
        case '*':
            num[2] = num[1] * num[0];
            break;
        case '/':
            if (num[1] != 0){
                num[2] = num[0] / num[1];
            } else {
                std::cout << "Bad";
                break;
            }
            break;
        default:
            std::cout << "Not correct operator";
            break; 
    }

    
    for (short i = 0; i < 3; i++){
        std::cout << num[i] << std::endl;
    }

    return 0;
}