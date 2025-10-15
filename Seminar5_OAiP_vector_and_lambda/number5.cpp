#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;


int main(){
    vector<int> v;
    v.reserve(20);

    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<> dis(-10000, 100);

    for (short i = 0; i < 20; i++){
        v.push_back(dis(gen));
    }

    sort(v.begin(), v.end(), [](int x, int y){return x <= y;});

    auto mxn = minmax_element(v.begin(), v.end(), [](int x, int y){
        return x < y;
    });

    cout << *mxn.first << " " << *mxn.second;

    cout << endl;
    cout << "-------------------";
    cout << endl;

    for (short i = 0; i != v.size(); i++){
        cout << v[i] << " ";
    }

    return 0;
}