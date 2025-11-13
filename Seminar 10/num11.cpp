#include <iostream>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <string>
#include <vector>
#include <algorithm>


int main(){
    std::ifstream file("vibration_log.txt");

    if (file.fail()){
        std::cout << "Error with open";
        return 1;
    }

    std::vector<double> data;
    double val = 0.0;

    while (file >> val){
        data.push_back(val);
    }

    file.close();

    std::ofstream File("vibration_report.txt");

    if (File.fail()){
        std::cout << "Error";
        return 1;
    }

    std::vector<double> report;
    std::copy_if(data.begin(), data.end(), std::back_inserter(report), [](double x){
        return x > 0.05;
    });

    double sum = std::accumulate(report.begin(), report.end(), 0.0);
    double avg = sum / report.size();
    auto mxn = std::minmax_element(report.begin(), report.end());

    File << std::fixed << std::setprecision(4);

    File << "Amount of measures:" << data.size() << "\n";

    File << "Amount of measures(ampl > 0.05): ";
    for (short i = 0; i < report.size(); i++){
        File << report[i];
        if (i < report.size() - 1) File << " ";
    } File << "\n";

    File << "Average: " << avg << "\n";
    File << "Max: " << *mxn.second << "\n";
    File << "Min: " << *mxn.first;

    File.close();

    return 0;
}