#include <iostream>
#include <memory>
#include <vector>

void procA(std::shared_ptr<std::vector<int>> buf){
    for (short i = 0; i < buf -> size(); i++){
        (*buf)[i] += 1;
    }
}


void procB(std::shared_ptr<std::vector<int>> buf){
    for (short i = 0; i < buf -> size(); i++){
        (*buf)[i] *= 2;
    }
}


void print(std::shared_ptr<std::vector<int>> buf){
    for (short i = 0; i < buf -> size(); i++){
        std::cout << (*buf)[i] << " ";
    }
}

int main(){
    std::shared_ptr<std::vector<int>> buffer = std::make_shared<std::vector<int>>();

    for (short i = 0; i < 10; i++){
        buffer -> push_back(i + 1);
    }

    procA(buffer);
    procB(buffer);
    print(buffer);

    return 0;
}