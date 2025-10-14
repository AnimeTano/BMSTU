#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;


int main(){
    vector<int> numb;
    numb.reserve(20);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 567);

    for (short i = 0; i < 20; i++){
        numb.push_back(dis(gen));
    }

    for (short i = 0; i < 20; i++){
        std::cout << numb[i] << " ";
    }

    auto maxelem = max_element(numb.begin(), numb.end(), [](int x, int y){
        return x < y;
    });

    cout << endl;
    cout << "---------------------";
    cout << endl;

    cout << *maxelem;

    return 0;
}