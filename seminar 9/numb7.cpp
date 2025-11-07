#include <iostream>
#include <memory>
#include <string>
#include <cstring>


bool gl(char s){
    s = std::tolower(s);
    return (s == 'e' || s == 'y' || s == 'u' || s == 'i' || s == 'o' || s == 'a');
}


bool ischar(char s){
    s = std::tolower(s);
    return std::isalpha(s);
}

int main(){
    std::string stroka; 

    std::cout << "Enter string:";
    getline(std::cin, stroka);

    int n = stroka.size();

    std::unique_ptr<char[]> ptr = std::make_unique<char[]>(n + 1);
    std::strcpy(ptr.get(), stroka.c_str());

    short amount[2] = {0, 0};

    for (short i = 0; i < n; i++){
        if (gl(ptr[i])){
            amount[0]++;
        } else if (ischar(ptr[i])) amount[1]++;
    }

    std::cout << "Gl:" << amount[0] << "\n";
    std::cout << "Sgl:" << amount[1] << std::endl;

    short ind = 0;
    std::unique_ptr<char[]> glas = std::make_unique<char[]>(amount[0] + 1);
    for (short i = 0; i < n; i++){
        if (gl(ptr[i])){
            glas[ind] = ptr[i];
            ind++;
        } 
    }
    glas[amount[0]] = '\0';

    std::cout << "Glas:" << glas.get() << std::endl;

    return 0;
}