#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>


int main(){
    std::string s, sub1, sub2, res = "";
    short pos = 0;

    std::cout << "Enter string:";
    getline(std::cin, s);
    std::cout << "Enter substring while change:";
    getline(std::cin, sub1);
    std::cout << "Enter substring on str:";
    getline(std::cin, sub2);

    while ((pos = s.find(sub1, pos)) != std::string::npos){
        s.replace(pos, sub1.size(), sub2);
        pos += sub2.size();
    }
    
    std::cout << s;

    return 0;
}