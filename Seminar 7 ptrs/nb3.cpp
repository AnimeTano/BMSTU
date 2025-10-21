#include <iostream>
#include <vector>


void myStrCat(char* dest, const char* src){
    short cnt = 0, c = 0;

    while (*(src + cnt) != '\0'){
        cnt++;
    }

    while (dest[c] != '\0'){
        dest[cnt + c] = src[c];
        c++;
    }

}


int main(){
    const short size = 500;
    char str1[size], str2[size];

    std::cout << "Enter string 1:";
    std::cin.getline(str1, size);

    std::cout << "Enter string 2:";
    std::cin.getline(str2, size);

    myStrCat(str1, str2);

    std::cout << str1;


    return 0;
}