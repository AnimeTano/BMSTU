#include <iostream>


int main(){
    int n, sm = 0;
    short *arr = new short [n];

    std::cout << "Enter length of array:";
    std::cin >> n;

    for (short i = 0; i < n; i++){
        std::cout << "Enter element:";
        std::cin >> arr[i];
        sm += arr[i];
    }

    std::cout << "Sr:" << (sm / n);

    return 0;
}