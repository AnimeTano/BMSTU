#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>


int main(){
    std::string str1, str2;

    std::cout << "Enter string 1:";
    getline(std::cin, str1);

    std::cout << "Enter string 2:";
    getline(std::cin, str2);

    for (short i = 0; i < str1.size(); i++){
        str1[i] = tolower(str1[i]);
    }

    for (short i = 0; i < str2.size(); i++){
        str2[i] = tolower(str2[i]);
    }

    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());

    if (str1 == str2) std::cout << "Yes" << "\n";
    else std::cout << "No" << "\n";

    return 0;
}