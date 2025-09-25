#include <iostream>


int main(){
    const short n = 15;
    double arr[n];
    short index[2] = {0, 0};
    double mxn[2] = {100005000, -100005000}; // min, max

    std::cout << "Enter elements of array:" << std::endl;

    for (short i = 0; i < n; i++){
        std::cin >> arr[i];

        if (arr[i] > mxn[1]){
            mxn[1] = arr[i];
            index[1] = (i + 1);
        }

        if (arr[i] < mxn[0]){
            mxn[0] = arr[i];
            index[0] = (i + 1);
        }
    }

    if (index[0] == 2 && index[1] == 1){
        for (short i = 0; i < n; i++){
            arr[i] = (arr[i] / 2.0);
        }
    }

    std::cout << "----------" << std::endl;

    for (short i = 0; i < n; i++){
        std::cout << arr[i] << std::endl;
    }

    return 0;
}