#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;


int main(){
    vector<int> numb;
    numb.reserve(15);

    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<> dis(-200, 200);

    for (short i = 0; i < 15; i++){
        numb.push_back(dis(gen));
    }

    for (short i = 0; i < 15; i++){
        cout << numb[i] << " ";
    } cout << endl;

    numb.erase(remove_if(numb.begin(), numb.end(), [](int x){return x < 0;}), numb.end());

    cout << "------------" << endl;

    for (short i = 0; i != numb.size(); i++){
        cout << numb[i] << " ";
    }

    return 0;
}