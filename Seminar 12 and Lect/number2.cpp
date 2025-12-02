#include <iostream>
#include <queue>
#include <string>


void processEvents(std::queue<std::string>& eventQueue) {
    if (eventQueue.empty()) {
        std::cout << "Empty\n";
        return;
    }

    bool ok = true;

    while (!eventQueue.empty()){
        std::string cur = eventQueue.front();
        eventQueue.pop();
        std::cout << "Event: " << cur << "\n";
    }
}

void addEvents(std::queue<std::string>& eventQueue, const std::string& event) {
    eventQueue.push(event);
    std::cout << "Added event: " << event << "\n";
}

int main() {
    std::queue<std::string> q;

    addEvents(q, "login: client_001, username: Will Byers");
    addEvents(q, "message: client_002, Hello everyone!");
    addEvents(q, "request: client_001, get_profile");

    processEvents(q);
    processEvents(q);

    return 0;
}