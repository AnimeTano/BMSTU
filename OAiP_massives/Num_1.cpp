#include <iostream>
#include <cmath>


int main(){
    int n;
    int count;

    std::cout << "Enter length of array:";
    std::cin >> n;

    int * array = new int[n];

    for (int i = 0; i < n; i++){
        std::cout << "Enter " << (i + 1) << " element:";
        std::cin >> array[i];

        if (array[i] > pow(2, i + 1)){
            count += 1;
        }
    }


    std::cout << "Count:" << count;
    
    return 0;
}