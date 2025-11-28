#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>


int main(){
    std::ofstream outfile("numbers.bin", std::ios::binary);
    int numbers[] = {15, 23, 7, 42, 18, 91, 3, 56, 77, 10};
    const int count = sizeof(numbers) / sizeof(numbers[0]);

    if (outfile.fail()){
        std::cout << "Error";
        return 1;
    }

    outfile.write(reinterpret_cast<const char*>(numbers), sizeof(numbers));
    outfile.close();

    std::ifstream file("numbers.bin", std::ios::binary);

    if (file.fail()){
        std::cout << "Error";
        return 1;
    }

    file.seekg(0, std::ios::end);
    size_t sz = file.tellg();
    file.seekg(0, std::ios::beg);

    int num[count];
    file.read(reinterpret_cast<char*>(num), sz);
    file.close();

    int sum = 0;

    for (short i = 0; i < count; i++){
        std::cout << num[i] << "\n";
        sum += num[i];
    }

    std::cout << "Summa:" << sum;

    return 0;
}