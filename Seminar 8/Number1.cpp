#include <iostream>


void swapPointers(int **a, int **b){
    int *temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int x = 2, y = 5;
    int *p1 = &x, *p2 = &y;

    std::cout << "Before swap: ";
    std::cout << "x:" << *p1 << ", y:" << *p2 << "\n";
    std::cout << p1 << "  " << p2 << "\n";

    swapPointers(&p1, &p2);

    std::cout << "After swap: ";
    std::cout << "x:" << *p1 << ", y:" << *p2 << "\n";
    std::cout << p1 << "  " << p2;

    return 0;
}