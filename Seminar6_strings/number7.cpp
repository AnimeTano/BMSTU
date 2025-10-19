#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>


int main(){
    std::string s;
    std::string new_s;

    std::cout << "Enter string:";
    getline(std::cin, s);

    short count = 0;
    char st = s[0];
    
    for (short i = 0; i < s.size(); i++){

        if (st == s[i]){
            count++;
        } else {
            new_s += st;
            new_s += std::to_string(count);
            st = s[i];
            count = 1;
        }
    }

    new_s += st;
    new_s += std::to_string(count);

    std::cout << "String:" << new_s;

    return 0;
}