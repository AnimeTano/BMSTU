#include <iostream>


int main(){
    short n;
    short *arr = new short[n];
    std::cout << "Enter size of array:" << std::endl;
    std::cin >> n;
    int mxn[2] = {10005000, -10005000};

    for (short i = 0; i < n; i++){
        std::cout << "Enter elements:";
        std::cin >> arr[i];

        if (arr[i] > mxn[1]){
            mxn[1] = arr[i];
        }
        if (arr[i] < mxn[0]){
            mxn[0] = arr[i];
        }
    }

    std::cout << "Max:" << mxn[1] << std::endl;
    std::cout << "Min:" << mxn[0];
    return 0;
}