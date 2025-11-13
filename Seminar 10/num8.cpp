#include <iostream>
#include <fstream>
#include <string>


int main(){
    std::ifstream file1("file1.txt");
    std::ifstream file2("file2.txt");

    if (file1.fail() || file2.fail()){
        std::cout << "Error with open";
        return 1;
    }

    std::string line1, line2;
    bool ok = true;

    while (ok){
        std::getline(file1, line1);
        std::getline(file2, line2);

        if (line1 != line2) ok = false;
        if (!file1 && !file2) break;
    }

    if (ok){
        std::cout << "Files are identical";
    } else std::cout << "Files are different";

    file1.close();
    file2.close();

    return 0;
}