#include <iostream>
#include <vector>


void myStrCopy(char* dest, const char* src){
    short cnt = 0;

    while ((dest[cnt] = src[cnt]) != '\0'){
        cnt++;
    }

}


int main(){
    const short size = 500;
    char stroka[size], new_string[size];

    std::cout << "Enter string:";
    std::cin.getline(stroka, size);

    myStrCopy(new_string, stroka);

    std::cout << new_string;

    return 0;
}