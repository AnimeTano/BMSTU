#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>


bool isletter(char letter){
    return std::isalnum(letter) || letter == '+' || letter == '-' || letter == '.';
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
    std::vector<std::string> new_s;

    std::cout << "Enter string:";
    std::cin.getline(s, 500);

    std::vector<std::string> words = LineSpliting(s);

    for (short i = 0; i < words.size(); i++){
        std::string rev = words[i];
        std::reverse(rev.begin(), rev.end());
        new_s.push_back(rev);
    }

    for (short i = 0; i < new_s.size(); i++){
        std::cout << new_s[i];
        if (i < new_s.size() - 1){
            std::cout << " ";
        }
    }

    return 0;
}