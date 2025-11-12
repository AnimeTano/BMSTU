#include <iostream>
#include <fstream>
#include <string>


int main(){
    std::ifstream file("input.txt");

    if (file.fail()){
        std::cout << "Error";
        return 1;
    }

    std::string line;
    short count = 0;

    while(std::getline(file, line)){
        count++;
    }

    std::cout << "Amount of strings:" << count << "\n";

    file.close();

    return 0;
}