#include <iostream>


int main(){
    const short n = 10;
    int arr[n];
    int mnx[2] = {100005000, -1000500}; // min, max
    int index[2] = {0, 0};

    std::cout << "Enter elements of array:" << std::endl;

    for (short i = 0; i < n; i++){
        std::cin >> arr[i];

        if (arr[i] > mnx[1]){
            mnx[1] = arr[i];
            index[1] = (i + 1);
        }

        if (arr[i] < mnx[0]){
            mnx[0] = arr[i];
            index[0] = (i + 1);
        }
    }

    if (index[1] == 2 && index[0] == 5){
        for (short i = index[0]; i < n; i++){
            arr[i] = mnx[1];
        }
    }

    std::cout << "----------" << std::endl;
    
    for (short i = 0; i < n; i++){
        std::cout << arr[i] << std::endl;
    }

    return 0;
}