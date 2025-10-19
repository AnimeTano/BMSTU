#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>


int main(){
    std::string A;
    std::string B;

    std::cout << "Enter word A:";
    getline(std::cin, A);

    std::cout << "Enter word B:";
    getline(std::cin, B);

    bool ok = true;

    for (short i = 0; i < B.size(); i++){
        bool found = false;

        for (short j = 0; j < A.size(); j++){
            if (A[j] == B[i]){
                found = true;
                break;
            }
        }

        if (!found){
            ok = false;
            break;
        }
    }

    if (!ok){
        std::cout << "No";
    } else std::cout << "Yes";


    return 0;
}