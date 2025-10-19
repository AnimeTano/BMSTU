#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>


std::string substr(std::string word1, std::string word2){
    std::string longest, substr = "";
    short mx = 0;

    for (short start = 0; start < word1.size(); start++){
        for (short end = (start + 1); end < word1.size() + 1; end++){
            substr = word1.substr(start, end - start);

            if (word2.find(substr) != std::string::npos){
                if (substr.size() > mx){
                    mx = substr.size();
                    longest = substr;
                }
            }
        }
    }

    return longest;
}


int main(){
    std::string str1;
    std::string str2;

    std::cout << "Enter string 1:";
    getline(std::cin, str1);

    std::cout << "Enter string 2:";
    getline(std::cin, str2);

    std::cout << substr(str1, str2);

    return 0;
}