#include <iostream>


int main(){
    const short n = 10;
    int arr[n];
    
    int a[2] = {100555, -10005000}; //min, max 
    int index[2] = {0, 0}; // min, max

    std::cout << "Enter elements of array:" << std::endl;

    for (short i = 0; i < n; i++){
        std::cin >> arr[i];

        if (arr[i] > a[1]){
            a[1] = arr[i];
            index[1] = (i + 1);
        }

        if (arr[i] < a[0]){
            a[0] = arr[i];
            index[0] = (i + 1);
        }
    }

    if (index[0] == 5 && index[1] == 10){
        std::cout << "Sr:" << (a[0] + a[1]) / 2;
    }
    else {
        std::cout << "Oh, no";
    }

    return 0;
}