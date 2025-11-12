#include <iostream>
#include <fstream>
#include <string>


int main(){
    std::ifstream file("input.txt");

    if (file.fail()){
        std::cout << "Error";
        return 1;
    }

    std::string word;
    int count = 0;

    while (file >> word){
        count++;
    }

    std::cout << "Amount of words: " << count;

    file.close();

    return 0;
}