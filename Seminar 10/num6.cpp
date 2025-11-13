#include <iostream>
#include <fstream>
#include <string>


int main(){
    std::ofstream file("output.txt");

    if (file.fail()){
        std::cout << "Error with create file";
        return 1;
    }

    std::cout << "Enter string(empty string will end programm): ";
    std::string input;
    bool ok = true;

    while (ok){
        getline(std::cin, input);

        if (input.empty()) ok = false;

        file << input << "\n";
    }

    file.close();

    std::ifstream File("output.txt");

    if (File.fail()){
        std::cout << "Error with open";
        return 1;
    }

    std::cout << "=====File===== <<\n";
    std::string line;

    while (std::getline(File, line)){
        std::cout << line << "\n";
    }

    File.close();

    return 0;
}