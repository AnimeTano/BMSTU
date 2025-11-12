#include <iostream>
#include <fstream>
#include <string>


int main(){
    std::ifstream File("input.txt");

    if (File.fail()){
        std::cout << "Error";
        return 1;
    }

    std::string line;

    while (std::getline(File, line)){
        std::cout << line << "\n";
    }

    File.close();

    if (File.good()) std::cout << "Error";

    return 0;
}