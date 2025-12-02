#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


union Variant {
    int ivalue;
    double dvalue;
    char cvalue;
};


int main(){
    Variant type;
    char c;

    std::cout << "Enter type of data (i - int, d - double, c - char):";
    std::cin >> c;

    switch (c){
        case 'i':
            std::cout << "Enter integer: ";
            std::cin >> type.ivalue;
            std::cout << "\nEntered: " << type.ivalue << "\n";
            break;
        case 'd':
            std::cout << "Enter double: ";
            std::cin >> type.dvalue;
            std::cout << "\nEntered: " << type.dvalue << "\n";
        
            break;
        case 'c':
            std::cout << "Enter char: ";
            std::cin >> type.cvalue;
            std::cout << "\nEntered: " << type.cvalue << "\n";
            break;
        default:
            std::cout << "Unacceptable input!";
            return 1;
    }
}