#include <iostream>
#include <string>
#include <vector>


struct Command {
    std::string name;
    int value;
};


void parseCommand(const char* input, std::vector<Command>& buffer){
    Command lt;
    lt.value = 0;

    short start = 0;
    const char* start_str = input;
    const char* end = input;

    while (*end != ' ' && *end != '\0') end++;

    lt.name = std::string(start_str, end);

    if (*end == ' '){
        end++;

        while (std::isdigit(*end)){
            lt.value = lt.value * 10 + (*end - '0');
            end++;
        }
    }

    buffer.push_back(lt);
}


int main(){
    std::vector<Command> buffer;
    
    parseCommand("FORWARD 10", buffer);
    parseCommand("TURN 90", buffer);
    parseCommand("STOP", buffer);

    for (auto el : buffer){
        std::cout << "Command:" << el.name << ", Value:" << el.value << "\n";
    }

    return 0;
}