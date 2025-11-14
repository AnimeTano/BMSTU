#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
#include <chrono>


long long BubbleSort(std::vector<int> arr){
    auto start = std::chrono::high_resolution_clock::now();

    for (auto i = 0; i < (arr.size() - 1); i++){
        for (auto j = 0; j < (arr.size() - i - 1); j++){
            if (arr[j] > arr[j + 1]){
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    
    return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}


long long InsertionSort(std::vector<int> arr){
    auto start = std::chrono::high_resolution_clock::now();
    
    for (size_t i = 1; i < arr.size(); i++){
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    auto end = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}


auto MergeSort(std::vector<int> arr){
    auto st = std::chrono::high_resolution_clock::now();

    std::vector<int> temp(arr.size());

    for (size_t i = 1; i < arr.size(); i *= 2){
        for (size_t left = 0; left < arr.size(); left += (2 * i)){
            auto mid = std::min(left + i - 1, arr.size() - 1);
            auto right = std::min(left + 2 * i - 1, arr.size() - 1);

            int j = left, k = mid + 1, l = left;

            while (j <= mid && k <= right){
                if (arr[j] <= arr[k]){
                    temp[l++] = arr[j++];
                } else {
                    temp[l++] = arr[k++];
                }
            }

            while (j <= mid) temp[l++] = arr[j++];
            while (k <= right) temp[l++] = arr[k++];

            for (auto p = left; p <= right; p++){
                arr[p] = temp[p];
            }
        }
    }

    auto end = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::milliseconds>(end - st).count();
}


auto part(std::vector<int>& arr, int left, int right){
    int piv = arr[right];
    int i = left - 1;

    for (size_t j = left; j < right; j++){
        if (arr[j] <= piv){
            i++;
            auto temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    auto temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;

    return i + 1;
}


void quick(std::vector<int>& arr, int left, int right){
    if (left < right){
        int mid = part(arr, left, right);
        quick(arr, left, mid - 1);
        quick(arr, mid + 1, right);
    }
}


auto QuickSort(std::vector<int> arr){
    auto start = std::chrono::high_resolution_clock::now();
    
    quick(arr, 0, arr.size() - 1);

    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}


auto AutoSort(std::vector<int> arr){
    auto start = std::chrono::high_resolution_clock::now();
    
    std::sort(arr.begin(), arr.end());

    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}


std::vector<int> GenerateArray(int size){
    std::vector<int> massive(size);
        
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(-1000000, 1000000);

    int *ptr = &massive[0];

    for (auto i = 0; i < size; i++){
        *(ptr + i) = dis(gen);
    }

    return massive;
}


int main(){
    auto start = std::chrono::high_resolution_clock::now();
    int size = 10000;
    double arr[5] = {0.0};

    /*
    std::cout << "Time of Bubble Sort: " << BubbleSort(GenerateArray(size)) << " Milliseconds\n";
    std::cout << "Time of Insertion Sort: " << InsertionSort(GenerateArray(size)) << " Milliseconds\n";
    std::cout << "Time of Merge Sort: " << MergeSort(GenerateArray(size)) << " Milliseconds\n";
    std::cout << "Time of Quick Sort: " << QuickSort(GenerateArray(size)) << " Milliseconds\n";
    std::cout << "Time of Basic Sort: " << AutoSort(GenerateArray(size)) << " Milliseconds\n";
    */

    for (short i = 0; i < 10; i++){
        for (short j = 0; j < 5; j++){
            switch (j) {
            case 0:
                arr[j] += BubbleSort(GenerateArray(size));
                break;
            case 1:
                arr[j] += InsertionSort(GenerateArray(size));
                break;
            case 2:
                arr[j] += MergeSort(GenerateArray(size));
                break;
            case 3:
                arr[j] += QuickSort(GenerateArray(size));
                break;
            case 4:
                arr[j] += AutoSort(GenerateArray(size));
                break;
            }
        }
    }

    for (short i = 0; i < 5; i++){
        arr[i] /= 10;
    }
    std::cout << "Average time:\n";
    std::cout << "Time of Bubble Sort: " << arr[0] << " Milliseconds\n";
    std::cout << "Time of Insertion Sort: " << arr[1] << " Milliseconds\n";
    std::cout << "Time of Merge Sort: " << arr[2] << " Milliseconds\n";
    std::cout << "Time of Quick Sort: " << arr[3] << " Milliseconds\n";
    std::cout << "Time of Basic Sort: " << arr[4] << " Milliseconds\n";
    
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Total time: ";
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " Milliseconds";

    return 0;
}