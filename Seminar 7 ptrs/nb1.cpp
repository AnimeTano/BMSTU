#include <iostream>
#include <vector>
#include <string>


int myStrLen(const char* stroka){
    short cnt = 0;

    while (*(stroka + cnt) != '\0'){
        cnt++;
    }

    return cnt;
}


int main(){
    const short size = 500;
    char stroka[size];

    std::cout << "Enter string:";
    std::cin.getline(stroka, size);

    std::cout << myStrLen(stroka);

    return 0;
}