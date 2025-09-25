#include <iostream>

int main(){
    int n;
    int mx = 0, count = 0;

    std::cout << "Enter length of array:";
    std::cin >> n;

    int *array = new int[n];

    for (int i = 0; i < n; i++){
        std::cout << "Enter " << (i + 1) << " element:";
        std::cin >> array[i];

        if (array[i] % 2 != 0){
            if (array[i] > mx){
                mx = array[i];
            }
        }
        else {
            count += 1;
        }
    }

    std::cout << "Count of chet numb:" << count << std::endl;
    std::cout << "Max from nechet:" << mx << std::endl;

    return 0;
}