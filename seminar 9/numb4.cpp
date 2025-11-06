#include <iostream>
#include <memory>


int main(){
    std::unique_ptr<int> ptr1 = std::make_unique<int>(42);

    std::cout << "Pointer 1:" << *ptr1 << "\n";

    std::unique_ptr<int> ptr2 = std::move(ptr1);

    if (ptr1 == nullptr) std::cout << "Gorrilaz - Feel Good Inc." << "\n";

    std::cout << "Pointer 2:" << *ptr2;

    return 0;
}