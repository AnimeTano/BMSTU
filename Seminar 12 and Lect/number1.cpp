#include <iostream>
#include <queue>
#include <string>


void addToQueue(std::queue<std::string>& queue, const std::string& person){
    queue.push(person);
}


void processQueue(std::queue<std::string>& queue){
    if (queue.empty()){
        std::cout << "Empty\n";
    } else {
        auto pers = queue.front();
        queue.pop();
        std::cout << pers << " processed and removed\n";
    }
}

int main(){
    std::queue<std::string> queue;

    addToQueue(queue, "Will Byers");
    addToQueue(queue, "Hopper");
    addToQueue(queue, "El");
    addToQueue(queue, "Eddie");

    for (short i = 0; i < 5; i++) processQueue(queue);

    return 0;
}