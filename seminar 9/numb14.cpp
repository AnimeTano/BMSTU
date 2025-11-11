#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>


int main(){
    short n = 0, m = 0;

    std::cout << "Enter size of matrix: ";
    std::cin >> n >> m;

    std::unique_ptr<double[]> matrix = std::make_unique<double[]>(n * m);

    std::cout << "Enter elements of matrix:\n";
    for (short i = 0; i < n; i++){
        for (short j = 0; j < m; j++){
            std::cin >> matrix[i * m + j];
        }
    }

    auto sumCol = [&]() -> std::vector<double> {
        std::vector<double> vec(m, 0.0);
        for (short i = 0; i < m; i++){
            for (short j = 0; j < n; j++){
                vec[i] += matrix[j * m + i];
            }
        }

        return vec;
    };

    std::vector<double> colSum = sumCol();

    auto MaxCol = [&]() -> std::pair<int, double> {
        auto it = std::max_element(colSum.begin(), colSum.end());
        short ind = std::distance(colSum.begin(), it);

        return {ind, *it};
    };
    
    auto [mxInd, mxVal] = MaxCol();

    std::cout << "Matrix:" << "\n";
    for (short i = 0; i < n; i++){
        for (short j = 0; j < m; j++){
            std::cout << matrix[i * m + j] << "\t";
        }
        std::cout << std::endl;
    }

    std::cout << "\nColumn sum:";
    for (short i = 0; i < colSum.size(); i++) {
        std::cout << colSum[i];
        if (i < (colSum.size() - 1)) {
            std::cout << ", ";
        }
    }

    std::cout << "\nColumn with max sum:" << (mxInd + 1) << " - (" << mxVal << ")";

    return 0;
}