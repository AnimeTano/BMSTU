#include <iostream>


int main(){
    const short n = 15;
    int arr[n];
    int mxn[2] = {10005000, -10005000}; // min, max
    short index[2] = {0, 0};

    std::cout << "Enter elements of array:" << std::endl;

    for (short i = 0; i < n; i++){
        std::cin >> arr[i];

        if (arr[i] > mxn[1]){
            mxn[1] = arr[i];
            index[1] = i;
        }

        if (arr[i] < mxn[0]){
            mxn[0] = arr[i];
            index[0] = i;
        }
    }

    if (mxn[0] == 0){
        for (short i = 0; i < index[0]; i++){
            arr[i] = 0;
        }
    }
    else if (mxn[1] == 0){
        for (short i = 0; i < index[1]; i++){
            arr[i] = 0;
        }
    }

    std::cout << "-------------" << std::endl;

    for (short i = 0; i < n; i++){
        std::cout << arr[i] << std::endl;
    }

    return 0;
}