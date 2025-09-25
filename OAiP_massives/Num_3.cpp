#include <iostream>


int main(){
    const short n = 15;
    double arr[n];

    short ind;
    double p = -100500;
    for (short i = 0; i < n; i++){
        std::cout << "Enter " << i + 1 << " element:";
        std::cin >> arr[i];

        if (arr[i] > p){
            p = arr[i];
            ind = i;
        }
    }

    double temp = arr[n-1];
    arr[-1] = arr[ind];
    arr[ind] = temp;

    for (short i = 0; i < n; i++){
        if (arr[i] < p){
            p = arr[i];
            ind = i;
        }
    }

    temp = arr[0];
    arr[0] = arr[ind];
    arr[ind] = temp;
    

    for (int i = 0; i < n; i++){
        std::cout << arr[i] << std::endl;
    }
}