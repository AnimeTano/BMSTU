#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


std::pair<std::string, std::string> Partition(std::string data){
    size_t pos = data.find('=');
    std::pair<std::string, std::string> name;

    if (pos != std::string::npos){
        name.first = data.substr(0, pos);
        name.second = data.substr(pos + 1);
    }

    return name;
}


int main(){
    std::ifstream infile("config.txt");

    if (infile.fail()){
        std::cout << "Error";
        return 1;
    }

    std::string changes;
    std::cout << "Enter string to change:";
    std::getline(std::cin, changes);

    std::vector<std::pair<std::string, std::string>> data;
    std::string line;
    bool ok = false;

    while (std::getline(infile, line)){
        auto st = Partition(changes);
        auto para = Partition(line);

        if (st.first == para.first){
            para.second = st.second;
            ok = true;
        }
        data.push_back(para);
    }

    infile.close();

    std::ofstream file("config.txt");

    if (file.fail()){
        std::cout << "Error";
        return 1;
    }

    for (const auto& i : data){
        file << i.first << "=" << i.second << "\n";
    }

    file.close();

    return 0;
}