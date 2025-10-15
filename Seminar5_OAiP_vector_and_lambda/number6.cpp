#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>


using namespace std;


int main(){
    vector<int> v = {2, 4, 6, 8, 10, 1, 14, 16, 18, 7, 35, 6, 1, 6, 32, 5, 7, 8, 0, 55};

    auto it = find(v.begin(), v.end(), 7);

    if (it != v.end()){
        cout << "Element " << *it << " with index:" << (it - v.begin());
    } else cout << "Not found";

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    int *ptr = &v[0];
    cout << endl;

    for (short i = 0; i < v.size(); i++){
        cout << i + 1 << " element:" << *(ptr + i) << endl;
    }

    return 0;
}