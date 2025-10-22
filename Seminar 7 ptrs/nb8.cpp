#include <iostream>
#include <vector>


const char* findSubstring(const char* text, const char* word){
    if (*word == '\0') return text;

    for (short i = 0; *(text + i) != '\0'; i++){
        bool ok = true;
        for (short j = 0; *(word + j) != '\0'; j++){
            if ((text[i + j] == '\0') || (text[i + j] != *(word + j))){
                ok = false;
                break;
            }
        }
        if (ok) return (text + i);
    }

    return nullptr;
}


int main(){
    const short size = 500;
    char str1[size], str2[size];

    std::cout << "Enter string 1:";
    std::cin.getline(str1, size);

    std::cout << "Enter string 2:";
    std::cin.getline(str2, size);

    const char* res = findSubstring(str1, str2);

    if (res != nullptr){
        std::cout << "Substr:" << res << "\n";
    } else std::cout << "Not found in main string";

    return 0;
}