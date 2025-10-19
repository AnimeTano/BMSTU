#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>


bool up(char letter){
    return (letter >= 'A' && letter <= 'Z');
}


bool lw(char letter){
    return (letter >= 'a' && letter <= 'z');
}

int main(){
    std::string s;
    short shift = 0;

    std::cout << "Enter string:";
    getline(std::cin, s);

    std::cout << "Enter shift:";
    std::cin >> shift;

    for (short i = 0; i < s.size(); i++){
        if (up(s[i])) s[i] = (s[i] - 'A' + shift) % 26 + 'A';
        if (lw(s[i])) s[i] = (s[i] - 'a' + shift) % 26 + 'a';
    }

    std::cout << "Shifted string:" << s; 

    return 0;
}