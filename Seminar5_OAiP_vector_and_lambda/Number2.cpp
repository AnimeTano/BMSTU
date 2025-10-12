#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for_each(v.begin(), v.end(), [](int &x){x *= 2;});

    for (short i = 0; i < 10; i++){
        cout << v[i] << " ";
    }

    return 0;
}