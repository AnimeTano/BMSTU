#include <iostream>
#include <vector>


int main(){
    short n = 0;

    std::cout << "Enter amount of elements for vector:";
    std::cin >> n;

    std::vector<int> vec(n);

    std::cout << "Enter elements of vector:";
    for (short i = 0; i < n; i++){
        std::cin >> vec[i];
    }

    for (int *ptr = vec.data(); ptr < vec.data() + vec.size(); ptr++){
        *ptr += 10;
    }

    for (short el : vec){
        std::cout << el << " ";
    }

    return 0;
}