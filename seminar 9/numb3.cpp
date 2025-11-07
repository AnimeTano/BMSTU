#include <iostream>
#include <memory>
#include <cmath>


void fillArray(std::unique_ptr<int[]>& arr, int n){
    for (short i = 0; i < n; i++){
        arr[i] = (pow(i, 2));
        std::cout << arr[i] << " ";
    }
}

int main(){
    short n = 0;

    std::cout << "Enter size of massive:";
    std::cin >> n;

    std::unique_ptr<int[]> massive = std::make_unique<int[]>(n);
    
    fillArray(massive, n);

    return 0;
}