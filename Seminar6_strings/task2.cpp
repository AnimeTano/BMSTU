#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>


int main(){
    std::string s;
    std::string answer;
    char symb;

    std::cout << "Enter string:";
    getline(std::cin, s);
    std::cout << "Enter symbol:";
    std::cin >> symb;

    for (short i = 0; i < s.size(); i++){
        if (s[i] != symb) answer += s[i];
    }

    std::cout << "Result:" << answer;

    return 0;
}