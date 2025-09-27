#include <iostream>


int main(){
    short n, count;
    int *arr = new int[n];

    std::cout << "Enter length:";
    std::cin >> n;

    for (short i = 0; i < n; i++){
        std::cout << "Enter element:";
        std::cin >> arr[i];

        if (arr[i] % 2 == 0){
            count += 1;
        }
    }

    std::cout << "Count:" << count;

    return 0;
}