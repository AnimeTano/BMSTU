#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    vector<int> numbers(10);

    for (short i = 1; i < 11; i++){
        numbers.push_back(i);
    }

    for_each(numbers.begin(), numbers.end(), [](int x){
        cout << x << "\n";});

    return 0;
}