#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>


int main(){
    std::string s;

    std::cout << "Enter your string:";
    getline(std::cin, s);

    s.erase(remove(s.begin(), s.end(), ' '), s.end());

    for (short i = 0; i < s.size(); i++){
        s[i] = tolower(s[i]);
    }


    short sz = s.size();
    char *str1 = &s[0], *str2 = &s[sz - 1];
    bool ok = true;

    for (short i = 0; i < sz / 2; i++){
        if ((*(str1 + i)) != (*(str2 - i)) ){
            ok = false;
            break;
        }
    }

    if (ok){
        std::cout << "Palindrom";
    } else std::cout << "Not in Palindrom";

    return 0;
}