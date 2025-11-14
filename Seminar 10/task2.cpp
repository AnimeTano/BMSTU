#include <iostream>
#include <chrono>
#include <thread>


int main(){
    int n = 0;

    std::cout << "Enter your number:";
    std::cin >> n;

    for (short i = n; i > 0; i--){
        std::cout << "Remain: " << i << " second\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << "The end!";

    return 0;
}