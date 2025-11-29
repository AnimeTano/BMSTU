#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <random>


auto Time = [](const std::string& description, auto&& func){
    auto start = std::chrono::steady_clock::now();
    func();
    auto end = std::chrono::steady_clock::now();
    auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << description << ": " << dur.count() << "ms" << "\n";

    return dur;
};


std::vector<int> Adding(const int size){
    std::vector<int> numb;
    numb.reserve(size);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 10000);

    for (size_t i = 0; i < size; i++){
        numb.push_back(dist(gen));
    }

    return numb;
}


void One(const std::vector<int>& numb){
    auto On = Time("One after one", [&numb](){
        std::ofstream file("One.bin", std::ios::binary);

        if (file.fail()){
            std::cout << "Error";
            return;
        }

        for (const auto& num: numb){
            file.write(reinterpret_cast<const char*>(&num), sizeof(num));
        }

        file.close();
    });
}


void Every(const std::vector<int>& numb){
    auto every = Time("Everything at one time", [&numb](){
        std::ofstream file("One_time.bin", std::ios::binary);

        if (file.fail()){
            std::cout << "Error";
            return;
        }

        file.write(reinterpret_cast<const char*>(numb.data()), numb.size() * sizeof(int));
        file.close();
    });
}


int main(){
    const size_t data = 1500000;

    std::vector<int> numb = Adding(data);

    One(numb);
    Every(numb);

    return 0;
}