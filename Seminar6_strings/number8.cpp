#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>


int main(){
    std::string s;

    std::cout << "Enter string:";
    getline(std::cin, s);

    bool start = true;

    for (short i = 0; i < s.size(); i++){
        if (start && isalpha(s[i])){
            s[i] = toupper(s[i]);
            start = false;
        } else s[i] = tolower(s[i]);

        if (s[i] == '.' || s[i] == '!' || s[i] == '?'){
            start = true;
        }
    
    }

    std::cout << "String:" << s;

    return 0;
}