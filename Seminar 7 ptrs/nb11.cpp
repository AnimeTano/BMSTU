#include <iostream>
#include <vector>


int main(){
    short n = 0;
    int sum = 0;
    
    std::cout << "Enter amount of elements:";
    std::cin >> n;

    std::vector<int> vec(n);
    std::cout << "Enter elements for vector:";

    for (short i = 0; i < n; i++){
        std::cin >> vec[i];
    }

    int *ptr = &vec[0];

    for (short i = 0; i < n; i++){
        sum += *(ptr + i);
    }

    std::cout << "Summa:" << sum;

    return 0;
}