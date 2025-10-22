#include <iostream>
#include <vector>
#include <string>


int myStrCmp(const char* st1, const char* st2){
    if (st1 == nullptr && st2 == nullptr) return 0;
    if (st1 == nullptr) return -1;
    if (st2 == nullptr) return 1;

    while (*st1 != '\0' && *st2 != '\0'){
        if (*st1 != *st2) return (*st1 - *st2);

        st1++;
        st2++;
    }

    return (*st1 - *st2);
}

int main(){
    const short size = 500;
    char str1[size], str2[size];

    std::cout << "Enter string 1:";
    std::cin.getline(str1, size);

    std::cout << "Enter string 2:";
    std::cin.getline(str2, size);

    int ans = myStrCmp(str1, str2);

    if (ans == 0){
        std::cout << "Equal";
    } else if (ans < 0){
        std::cout << "First less, than second";
    } else std::cout << "Second less, than first";

    return 0;
}