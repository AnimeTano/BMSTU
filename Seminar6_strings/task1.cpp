#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>


bool isletter(char letter){
    return (letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z');
}


std::vector<std::string> LineSpliting(char* stroka){
    std::vector<std::string> words;
    std::string word;

    for (short i = 0; i <= strlen(stroka); i++){
        if (isletter(stroka[i]) && i < strlen(stroka)){
            word += stroka[i];
        } else {
            if (word.size() > 0){
                words.push_back(word);
                word.clear();
            }
        }
    }

    return words;
}


int main(){
    char s[500];

    std::cout << "Enter string:";
    std::cin.getline(s, 500);

    short count = 0, mx = 0;

    std::vector<std::string> words = LineSpliting(s);
    std::string ws;

    for (short i = 0; i < words.size(); i++){
        if (words[i].size() > mx){
            mx = words[i].size();
            ws = words[i];
        }
    }
    
    std::cout << ws;

    return 0;
}