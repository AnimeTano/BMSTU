#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>


int main(){
    std::string s;

    std::cout << "Enter string:";
    getline(std::cin, s);

    s.erase(std::remove_if(s.begin(), s.end(), ::isdigit), s.end());

    std::cout << "String without digits:" << s;

    return 0;
}