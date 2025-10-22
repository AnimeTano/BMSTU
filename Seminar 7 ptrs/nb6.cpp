#include <iostream>
#include <vector>
#include <string>


void reverse(char* str){
    short length = 0;

    while (*(str + length) != '\0'){
        length++;
    }

    for (short i = 0; i < length / 2; i++){
        char temp = str[length - i - 1];
        str[length - i - 1] = str[i];
        str[i] = temp;
    }

}

int main(){
    const short size = 500;
    char s[size];

    std::cout << "Enter string:";
    std::cin.getline(s, size);

    reverse(s);

    std::cout << "Rev:" << s;

    return 0;
}