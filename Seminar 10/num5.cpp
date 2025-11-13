#include <iostream>
#include <fstream>
#include <string>


int main(){
    std::ifstream file("input.txt");

    if (file.fail()){
        std::cout << "Error with opening";
        return 1;
    }

    char ch = ' ';
    int count = 0;

    while (file.get(ch)){
        count++;
    }

    file.close();

    std::cout << "Amount of chars in file:" << count;

    return 0;
}