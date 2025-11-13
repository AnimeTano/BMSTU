#include <iostream>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <string>
#include <vector>
#include <map>

int main() {
    std::ifstream file("power_log.txt");

    if (file.fail()) {
        std::cout << "Error with open";
        return 1;
    }

    std::map<const std::string, std::vector<double>> data;
    std::string line;

    while (std::getline(file, line)) {
        size_t pos = line.find(' ');
        size_t rpos = line.rfind(' ');

        if (pos != std::string::npos && rpos != std::string::npos && pos != rpos) {
            std::string name = line.substr(pos + 1, rpos - pos - 1);
            std::string power = line.substr(rpos + 1);

            auto pw = std::stod(power);

            data[name].push_back(pw);
        }
    }

    file.close();

    std::ofstream File("energy_report.txt");

    if (File.fail()) {
        std::cout << "Error with open";
        return 1;
    }

    File << std::fixed << std::setprecision(2);

    for (auto& [name, pow] : data) {
        auto sz = pow.size();
        double total = std::accumulate(pow.begin(), pow.end(), 0.0);
        double avg = total / sz;

        File << name << ": measurements = " << sz << ", total = " << total << " kWh, average = " << avg << " kW\n";
    }

    File.close();

    return 0;
}