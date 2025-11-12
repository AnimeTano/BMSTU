#include <iostream>
#include <fstream>
#include <string>


int main(){
    std::ifstream inFile("input.txt");
    std::ofstream outFile("copy.txt");

    if (inFile.fail()){
        std::cout << "Erroe with open";
        return 1;
    }

    if (outFile.fail()){
        std::cout << "Error with open";
        return 1;
    }

    std::string line;
    int count = 0;

    while (std::getline(inFile, line)){
        outFile << line << std::endl;
        count++;
    }

    inFile.close();
    outFile.close();

    std::cout << "Copied succesfully\n";
    std::cout << "Amount of copied lines:" << count;

    return 0;
}