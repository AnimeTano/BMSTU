#include <iostream>
#include <string>
#include <cstring>


void Memory(char **arr, short n){
    for (short i = 0; i < n; i++){
        delete[] arr[i];
    } delete[] arr;
}


void sort(char **words, short n){
    for (short i = 0; i < (n - 1); i++){
        for (short j = 0; j < (n - i - 1); j++){
            if (strcmp(words[j], words[j + 1]) > 0){
                char *temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }
}


void print(char **words, short n){
    for (short i = 0; i < n; i++){
        std::cout << words[i] << "\n";
    }
}


int main(){
    short n = 0;

    std::cout << "Enter amount of words:";
    std::cin >> n;
    std::cin.ignore();

    char **words = new char*[n];

    for (short i = 0; i < n; i++){
        std::string temp;
        getline(std::cin, temp);
        words[i] = new char[temp.size() + 1];
        strcpy(words[i], temp.c_str());
    }

    sort(words, n);

    std::cout << "Sorted words:" << "\n";
    print(words, n);

    Memory(words, n);

    return 0;
}