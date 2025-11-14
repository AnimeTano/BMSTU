#include <iostream>
#include <chrono>


int main(){
    long long n = 0;
    auto start = std::chrono::high_resolution_clock::now();

    std::cout << "Enter your number:";
    std::cin >> n;

    n = (n * (n + 1)) / 2;

    auto end = std::chrono::high_resolution_clock::now();
    auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    
    std::cout << "Time: " << dur.count() << "milsec\n";
    std::cout << "Sum(1 to n): " << n;

    return 0;
}