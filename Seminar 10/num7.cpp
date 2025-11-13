#include <iostream>
#include <fstream>


int main(){
    std::ifstream file("numbers.txt");

    if (file.fail()){
        std::cout << "Error with opening";
        return 1;
    }

    int amount = 0, sum = 0, n = 0;

    while (file >> n){
        amount++;
        sum += n;
    }

    if (amount == 0){
        std::cout << "There are  no numbers" << "\n";
        return 1;
    }

    float average = sum / amount;

    file.close();

    std::cout << "Amount of numbers: " << amount << "\n";
    std::cout << "Sum of numbers: " << sum << "\n";
    std::cout << "Average of numbers:" << average;

    return 0;
}