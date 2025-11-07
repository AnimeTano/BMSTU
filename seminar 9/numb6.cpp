#include <iostream>
#include <memory>


int main(){
    std::shared_ptr<float> ptr1 = std::make_shared<float>(2.72);  

    std::cout << "Pointer 1:" << *ptr1 << "\n";
    std::cout << "Number of links: " << ptr1.use_count() << "\n";

    std::shared_ptr<float> ptr2 = ptr1;

    std::cout << "Pointer 2:" << *ptr2 << "\n";
    std::cout << "Number of links: " << ptr1.use_count() << "\n";

    std::shared_ptr<float> ptr3 = ptr1;

    std::cout << "Pointer 3:" << *ptr3 << "\n";
    std::cout << "Number of links: " << ptr1.use_count() << "\n";

    ptr3.reset();
    std::cout << "Number of links after reset:" << ptr1.use_count();

    return 0;
}