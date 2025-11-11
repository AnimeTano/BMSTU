#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>


int main(){
    std::unique_ptr<std::string> part1 = std::make_unique<std::string>("Sensor data:");
    std::unique_ptr<std::string> part2 = std::make_unique<std::string>("Voltage stable.");
    std::unique_ptr<std::string> part3 = std::make_unique<std::string>("Sustem nominal.");
    std::vector<std::unique_ptr<std::string>> reportParts;

    reportParts.push_back(std::move(part1));
    reportParts.push_back(std::move(part2));
    reportParts.push_back(std::move(part3));

    auto concatParts = [&]() -> std::string {
        std::string fullstr;
        for (auto& part : reportParts){
            if (!fullstr.empty()){
                fullstr += '\n';
            }
            fullstr += *part;
        }

        return fullstr;
    };


    auto countwords = [](std::string& t,const std::string& search) -> short {
        short cnt = 0;
        auto pos = 0;

        std::string text = t;
        std::string lwd = search;

        std::transform(text.begin(), text.end(), text.begin(), ::tolower);
        std::transform(lwd.begin(), lwd.end(), lwd.begin(), ::tolower);

        while ((pos = text.find(lwd, pos)) != std::string::npos){
            cnt++;
            pos += lwd.size();
        }

        return cnt;
    };

    std::string st = concatParts();
    short count = countwords(st, "data");

    std::cout << "Report:\n" << st << "\n";
    std::cout << "Amount of word 'data': " << count;

    return 0;
}