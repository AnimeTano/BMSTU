#include <iostream> 
#include <memory>


int main(){
    short n = 0, m = 0;

    std::cout << "Enter size of matrix:";
    std::cin >> n >> m;

    std::unique_ptr<int[]> matrix = std::make_unique<int[]>(n * m);

    for (short i = 0; i < n; i++){
        for (short j = 0; j < m; j++){
            matrix[i * m + j] = i * j;
        }
    }

    for (short i = 0; i < n; i++){
        for (short j = 0; j < m; j++){
            std::cout << matrix[i * m + j] << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}