#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>


int main(){
    std::ifstream file("application.log");

    if (file.fail()){
        std::cout << "Error";
        return 1;
    }

    std::string line, s;
    short i = 1;

    while (std::getline(file, line)){
        s += line + "\n";
        
        if (s.size() > 1000000){
            std::ofstream outfile("log_par" + std::to_string(i++) + ".txt");
            outfile << s;

            outfile.close();
            s.clear();
        }
    }

    if (!s.empty()){
        std::ofstream outfile("log_par" + std::to_string(i) + ".txt");
        outfile << s;

        outfile.close();
    }

    file.close();

    return 0;
}