#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>


/*
std::vector<std::string> Split(std::string& str, char del) {
    std::vector<std::string> stroka;
    std::string token;
    
    while () {
        token.push_back(token);
    }

    return token;
}
*/


int main(){
    std::vector<std::string> routes = {
        "Moscow-Berlin",
        "Berlin-Paris",
        "Paris-Rome",
        "Rome-Moscow"
    };
    
    std::string name;
    std::cout << "Enter city to search:";
    getline(std::cin, name);

    std::shared_ptr<std::vector<std::string>> ptrRoutes = std::make_shared<std::vector<std::string>>(routes);

    auto countCity = [&]() -> int {
        return std::count_if(ptrRoutes -> begin(), ptrRoutes -> end(),
            [&name](const std::string& route){
                return route.find(name) != std::string::npos;
            });
    };

    auto sortByLength = [&](){
        std::sort(ptrRoutes -> begin(), ptrRoutes -> end(), [](std::string& x, std::string& y){
            return x.size() < y.size();
        });
    };

    auto concat = [&]() -> std::string {
        return std::accumulate(std::next(ptrRoutes -> begin()), ptrRoutes -> end(),
            ptrRoutes -> front(), [](std::string& x, std::string& y){
                return x + " -> " + y;
            });
    };

    std::cout << "Count: " << countCity() << std::endl;
    
    sortByLength();

    std::cout << "Sorted:\n";
    for (auto& rt : *ptrRoutes){
        std::cout << rt << "\n";
    }

    std::cout << "Route: " << concat() << std::endl;

    return 0;
}