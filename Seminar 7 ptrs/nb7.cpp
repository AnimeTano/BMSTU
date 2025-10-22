#include <iostream>
#include <vector>


bool isPalindrome(const char* str){
    short length = 0;
    bool ok = true;

    while (*(str + length) != '\0'){
        length++;
    }

    for (short i = 0; i < length / 2; i++){
        if (str[i] != str[length - i - 1]){
            ok = false;
            break;
        }
    }
    
    return ok;
}


int main(){
    const short size = 500;
    char s[size];

    std::cout << "Enter string:";
    std::cin.getline(s, size);

    if (isPalindrome(s)){
        std::cout << "Palindrome";
    } else std::cout << "No Palindrome";

    return 0;
}