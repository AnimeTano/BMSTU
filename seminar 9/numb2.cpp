#include <iostream>
#include <memory>


int main(){
    short n = 0;

    std::cout << "Enter size of massive:";
    std::cin >> n;

    std::unique_ptr<int[]> ptr = std::make_unique<int[]>(n);

    for (short i = 0; i < n; i++){
        ptr[i] = (i + 1);
        std::cout << ptr[i] << " ";
    }

    return 0;
}