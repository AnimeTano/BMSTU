#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <string>
#include <numeric>


int main(){
    std::ifstream infile("sensor_data.txt");

    if (infile.fail()){
        std::cout << "Error";
        return 1;
    }

    std::vector<double> temp, elem;
    auto tmp = 0.0;

    while (infile >> tmp){
        temp.push_back(tmp);
    }

    infile.close();

    std::ofstream file("sensor_data.txt");

    if (file.fail()){
        std::cout << "Error";
        return 1;
    }

    auto lambda = [](double x){
        return x >= -50.0 && x <= 50.0;
    };

    for (auto& x : temp){
        if (lambda(x)){
            elem.push_back(x);
        }
    }

    double avg = 0.0, sum = std::accumulate(elem.begin(), elem.end(), 0.0);
    avg = sum / elem.size();

    std::ofstream File("filtered.txt");

    if (File.fail()){
        std::cout << "Error";
        return 1;
    }

    for (const auto& x : elem){
        File << x << "\n";
    }

    File.close();

    return 0;
}