#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

int main(){
    std::string s;
    std::string chars;
    short count = 0;

    std::cout << "Enter string:";
    getline(std::cin, s);

    for (short i = 0; i < s.size(); i++){
        bool unique = true;

        for (short j = 0; j < i; j++){
            if (s[i] == s[j]){
                unique = false;
                break;
            }
        }

        if (unique){ 
            count++;
            chars += s[i];
            chars += " ";
        }
    }

    std::cout << "Amount:" << count << std::endl;
    std::cout << "Chars:";
    std::cout << chars;

    return 0;
}