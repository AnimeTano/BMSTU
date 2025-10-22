#include <iostream>
#include <vector>
#include <string>


int main(){
    std::string s;

    std::cout << "Enter string:";
    getline(std::cin, s);

    char *ptr = &s[0];

    for (short i = 0; i < s.size(); i++){
        if (*(ptr + i) == ' '){
            s[i] = '\0';
        }
    }

    std::cout << s;

    return 0;
}