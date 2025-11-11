#include <iostream>
#include <memory>


std::unique_ptr<int[]> createArray(int n){
    std::unique_ptr<int[]> ptr = std::make_unique<int[]>(n);

    for (short i = 0; i < n; i++){
        ptr[i] = (i + 1);
    }

    return ptr;
}

int main(){
    short n = 0;

    std::cout << "Enter size of massive:";
    std::cin >> n;

    std::unique_ptr<int[]> massive = createArray(n);

    for (short i = 0; i < n; i++){
        std::cout << massive[i] << " ";
    }

    return 0;
}