#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>


int main(){
    std::vector<std::vector<double>> temp(5, std::vector<double>(30));
    std::vector<std::vector<double>> pressure(5, std::vector<double>(100));


    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_real_distribution<double> temp_dis(0.0, 40.0);
    std::uniform_real_distribution<double> pressure_dis(0.0, 12.0);


    for (short i = 0; i < 5; i++){
        for (short j = 0; j < 30; j++){
            temp[i].push_back(temp_dis(gen));
        }
    }

    for (short i = 0; i < 5; i++){
        for (short j = 0; j < 100; j++){
            pressure[i].push_back(pressure_dis(gen));
        }
    }

    std::vector<double> average;
    average.reserve(5);

    std::transform(temp.begin(), temp.end(), average.begin(), [](std::vector<double>& x){
        return (accumulate(x.begin(), x.end(), 0.0) / x.size());
    });

    auto *ptr = &average[0];

    for (short i = 0; i < 5; i++){
        std::cout << *(ptr + i) << "\n";
    }

    double pres[5][2];

    for (short i = 0; i < 5; i++){
        auto mnx = std::minmax_element(pressure[i].begin(), pressure[i].end(), [](double x, double y){
            return x < y;
        });

        pres[i][0] = *mnx.first;
        pres[i][1] = *mnx.second;
    }

    std::cout << "Pressures:" << "\n";
    for (short i = 0; i < 5; i++){
        std::cout << "Min pres:" << pres[i][0] << "\n";
        std::cout << "Max pres:" << pres[i][1] << "\n";
    }


    std::vector<std::vector<double>> tempdif(5, std::vector<double>(29));
    std::vector<std::vector<double>> preddif(5, std::vector<double>(99));

    for (short i = 0; i < 5; i++){
        for (short j = 0; j < 29; j++){
            tempdif[i][j] = (temp[i][j + 1] - temp[i][j]);
        }
        for (short k = 0; k < 99; k++){
            preddif[i][k] = (pressure[i][k + 1] - pressure[i][k]);
        }
    }

    /*
    std::cout << "Remainder of temp:" << std::endl;
    for (short i = 0; i < 5; i++){
        for (short j = 0; j < 29; j++){
            std::cout << "i:" << i + 1 << " and j:" << (j + 1) << " is:" << tempdif[i][j] << "\n"; 
        }
    }

    std::cout << "Remainder of pres:" << std::endl;
    for (short i = 0; i < 5; i++){
        for (short j = 0; j < 99; j++){
            std::cout << "i:" << i + 1 << " and j:" << (j + 1) << " is:" << preddif[i][j] << "\n"; 
        }
    }
    */

    std::vector<double> mxtemp;
    mxtemp.reserve(5);

    std::transform(temp.begin(), temp.end(), mxtemp.begin(), [](auto x){
        auto mnx = std::minmax_element(x.begin(), x.end());
        return *mnx.second - *mnx.first;
    });

    std::cout << "Max temperature in every channel:" << "\n";
    for (short i = 0; i < 5; i++){
        std::cout << (i + 1) << " channel:" << mxtemp[i] << "\n";
    }

    std::vector<std::vector<double>> normalized = pressure;
    double minmax[5][2];

    for (short i = 0; i < 5; i++){
        auto t = std::minmax_element(pressure[i].begin(), pressure[i].end());

        minmax[i][0] = *t.first;
        minmax[i][1] = *t.second;
    }

    for (short i = 0; i < 5; i++){
        std::cout << "mn:" << minmax[i][0] << "\n";
        std::cout << "mx:" << minmax[i][1] << "\n";
    }

    for (short i = 0; i < 5; i++){
        double mn = minmax[i][0], mx = minmax[i][1];

        transform(pressure[i].begin(), pressure[i].end(), normalized[i].begin(), [mn, mx](double x){
            return (x - mn) / (mx - mn);
        });
    }

    std::cout << "Normalized elements::" << std::endl;
    for (short i = 0; i < 5; i++){
        for (short j = 0; j < 100; j++){
            std::cout << normalized[i][j] << "\n";
        }
        std::cout << "-----------" << "\n";
    }

    for_each(normalized.begin(), normalized.end(), [](auto x){
        for_each(x.begin(), x.end(), [](double t){
            if (t > 0.9) std::cout << t << "\n";
        });
    });

    std::cout << "------------" << "\n";

    std::sort(average.begin(), average.end(), [](auto x, auto y){
        return x < y;
    });

    double maxi = 0;
    for (short i = 0; i < 5; i++){
        if (average[i] > maxi) maxi = average[i];
    }

    std::cout << maxi;

    return 0;
}