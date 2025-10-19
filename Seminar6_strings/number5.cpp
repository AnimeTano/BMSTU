#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>


bool gl(char letter){
    std::string lt = "aeiouy";
    bool found = 0;

    for (short i = 0; i < lt.size(); i++){

        if (letter == lt[i]){
            found = true;
            break;
        }

    }

    return found;
}

bool sgl(char letter){
    std::string lt = "qwrtpsdfghjklzxcvbnm";
    bool found = 0;

    for (short i = 0; i < lt.size(); i++){

        if (letter == lt[i]){
            found = true;
            break;
        }

    }

    return found;
}


int main(){
    std::string s;

    std::cout << "Enter string:";
    getline(std::cin, s);

    short count[2] = {0, 0}; //гласные, согласные

    for (short i = 0; i < s.size(); i++){
        
        if (gl(tolower(s[i]))){
            count[0]++;
        }

        if (sgl(tolower(s[i]))){
            count[1]++;
        }

    }

    std::cout << "Gl:" << count[0] << "\n";
    std::cout << "Sgl:" << count[1]; 

    return 0;
}