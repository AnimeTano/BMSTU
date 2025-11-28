#include <iostream>
#include <fstream>
#include <string>
#include <vector>


void createConfig() {
    std::ofstream file("config.json");
    file << "{\n";
    file << " \"app_name\": \"My Application\",\n";
    file << " \"version\": \"1.0.0\",\n";
    file << " \"settings\": {\n";
    file << " \"max_connections\": 100,\n";
    file << " \"timeout\": 30,\n";
    file << " \"debug_mode\": true\n";
    file << " },\n";
    file << " \"database\": {\n";
    file << " \"host\": \"localhost\",\n";
    file << " \"port\": 5432,\n";
    file << " \"username\": \"admin\"\n";
    file << " }\n";
    file << "}";
    file.close();
    std::cout << "Конфигурационный файл создан\n";
}


void read(){
    std::ifstream file("config.json");

    if (file.fail()){
        std::cout << "Error";
        return;
    }

    std::string line;
    while (std::getline(file, line)){
        std::cout << line << "\n";
    }

    file.close();
}


void update(int time){
    std::ifstream file("config.json");

    if (file.fail()){
        std::cout << "Error";
        return;
    }

    std::string line;
    std::vector<std::string> ls;

    while (std::getline(file, line)){
        size_t pos = line.find("\"timeout\"");
        if (pos != std::string::npos){
            size_t poscol = line.find(':', pos);
            if (poscol != std::string::npos){
                line = line.substr(0, poscol + 1) + " " + std::to_string(time);
            }
        }
        ls.push_back(line);
    }

    file.close();

    std::ofstream outfile("config.json");
    
    if (outfile.fail()){
        std::cout << "Error";
        return;
    }

    for (const auto& i: ls){
        outfile << i;
    }
}


int main(){
    createConfig();
    read();
    
    update(60);
    read();

    return 0;
}