#include <iostream>
#include <vector>
#include <string>


int main(){
    std::string s;

    std::cout << "Enter string:";
    getline(std::cin, s);

    char *str = &s[0];

    for (short i = 0; i < s.size(); i++){
        if (*(str + i) == ' '){
            s[i] = '_';
        }
    }

    std::cout << s;

    return 0;
}