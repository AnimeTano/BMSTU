#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

int main(){
    std::string s;
    short k = 0;

    std::cout << "Enter string:";
    getline(std::cin, s);

    std::cout << "Enter k:";
    std::cin >> k;

    if (k > s.size()) {
        std::cout << "K can't be more than string length";
        return 0;
    }
    
    for (short i = 0; i <= (s.size() - k); i++){
        bool ok = true;

        for (short j = i; j < (i + k); j++){
            for (short l = (j + 1); l < (i + k); l++){
                if (s[j] == s[l]){
                    ok = false;
                    break;
                }
            }
            if (!ok) break;
        }
        
        if (ok){
            bool found = true;
            std::string cur = s.substr(i, k);
            
            for (short j = 0; j < i; j++){
                if (s.substr(j, k) == cur){
                    found = false;
                    break;
                }
            }
            
            if (found){
                std::cout << cur << std::endl;
            }
        }
    }

    return 0;
}