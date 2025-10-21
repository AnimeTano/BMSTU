#include <iostream>
#include <vector>
#include <string>


int main(){
    std::string stroka;
    char src ;
    short count = 0;

    std::cout << "Enter string:";
    getline(std::cin, stroka);

    std::cout << "Enter symb to search:";
    std::cin >> src;

    char *ptr = &stroka[0];

    for (short i = 0; i < stroka.size(); i++){
        if (*(ptr + i) == src){
            count++;
        }
    }

    std::cout << "Amount:" << count;

    return 0;
}