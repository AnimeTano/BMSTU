#include <iostream>

int main(){
    for (short i = 32; i <= 126; i++){
        std::cout << i << " Element is " << char(i) << std::endl;
    }

    return 0;
}