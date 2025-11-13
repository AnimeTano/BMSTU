#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <numeric>


int main(){
    std::ifstream file("temperature_data.txt");

    if (file.fail()){
        std::cout << "Error with open";
        return 1;
    }

    std::map<std::string, std::vector<double>> sensor;
    std::string line;

    while(std::getline(file, line)){
        size_t pos = line.find(' ');

        if (pos != std::string::npos){
            std::string name = line.substr(0, pos);
            std::string temp = line.substr(pos + 1);

            double tmp = std::stod(temp);
            sensor[name].push_back(tmp);
        }
    }

    file.close();

    std::ofstream File("report.txt");

    if (File.fail()){
        std::cout << "Error with open";
        return 1;
    }

    for (auto& [name, temp] : sensor){
        auto mnx = std::minmax_element(temp.begin(), temp.end());
        
        double sum = std::accumulate(temp.begin(), temp.end(), 0.0);
        double avg = sum / temp.size();
        
        File << name << ": min = " << *mnx.first << ", max = " << *mnx.second << ", avg = " << avg << "\n";
    }

    File.close();
    
    return 0;
}