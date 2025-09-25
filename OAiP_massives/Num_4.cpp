#include <iostream>

int main(){
    const short n = 15;
    double arr[n];
    double prod;
    double mx = -100500, mn = 1000500;
    short index[2] = {0, 0}; // min, max

    std::cout << "Enter elements of array:" << std::endl;
    
    for (short i = 0; i < n; i++){
        std::cin >> arr[i];

        if (arr[i] > mx){
            mx = arr[i];
            index[1] = i;
        }

        if (arr[i] < mn){
            mn = arr[i];
            index[0] = i;
        }
    }

    if (index[1] < index[0]){
        std::cout << "Multiply:" << (mx * mn);
    }
    else {
        std::cout << "Max righter, than min";
    }

    return 0;
}

//Что если два мин элемента будут с рахных сторон от максимума?