#include <iostream>
#include <chrono>
#include <thread>


int main(){
    long seconds = 0;

    std::cout << "Enter amount of seconds: ";
    std::cin >> seconds;

    auto hours = std::chrono::duration_cast<std::chrono::hours>(std::chrono::seconds(seconds));
    auto minutes = std::chrono::duration_cast<std::chrono::minutes>(std::chrono::seconds(seconds) - hours);
    auto sec = std::chrono::seconds(seconds) - hours - minutes;

    std::cout << hours.count() <<  " Hours " << minutes.count() << " Minutes " << sec.count() << " Seconds";

    return 0;
}