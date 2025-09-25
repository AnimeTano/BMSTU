#include <iostream>


int main(){
    short n;
    
    std::cout << "Enter amount of things u want to buy:";
    std::cin >> n;
    float *price = new float[n];
    short *amount = new short[n];
    std::string name;

    for (short i = 0; i < n; i++){

        std::cout << "Enter name of product:" << std::endl;
        std::cin >> name;

        std::cout << "Enter price of " << (i + 1) << " element" << std::endl;
        std::cin >> price[i];

        std::cout << "Enter amount of " << (i + 1) << " element" << std::endl;
        std::cin >> amount[i];

        std::cout << "Price of " << name << " is:" << (amount[i] * price[i]) << std::endl;
    }
    
    return 0;
}