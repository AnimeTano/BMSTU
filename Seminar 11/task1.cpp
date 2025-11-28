#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>


int main(){
    std::ifstream file("book.txt");

    if (file.fail()){
        std::cout << "Error";
        return 1;
    }

    std::vector<std::pair<int, int>> pos;
    std::vector<std::string> lst;
    short number = 0;
    std::string line, target;

    std::cout << "Enter word to search:";
    std::getline(std::cin, target);

    while (std::getline(file, line)){
        number++;
        size_t poson = 0;

        while ((poson = line.find(target, poson)) != std::string::npos){
            pos.emplace_back(number, poson);
            lst.push_back(line.substr(poson, target.size()));
            poson += target.size();
        }
    }

    file.close();

    std::ofstream File("result.txt");

    if (File.fail()){
        std::cout << "Error";
        return 1;
    }

    for (auto i = 0; i < pos.size(); i++){
        File << "Line " << pos[i].first << ", Position:" << pos[i].second << ", Word:" << lst[i] << "\n";
    }

    file.close();


    return 0;
}