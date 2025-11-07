#include <iostream>
#include <memory>


int main(){
    std::unique_ptr<int> ptr = std::make_unique<int>(10);

    std::cout << "Step 1:" << *ptr << "\n";
    
    *ptr = 25;

    std::cout << "Step 2:" << *ptr;

    return 0;
}