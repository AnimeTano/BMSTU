#include <iostream>

void BubbleSort(int arr[], int size) {
	for (int i = 0; i < (size - 1); i++) {
		for (int j = 0; j < (size - i - 1); j++) {
			if (arr[j] < arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


void print(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << std::endl;
	}
}


int main() {
	int n = 10;
	int array[10];
	int sm = 0;
	int mx = -10005000;

	for (int i = 0; i < n; i++) {
		std::cout << "Enter " << i << " number:";
		std::cin >> array[i];
		sm += array[i];
		if (array[i] > mx) {
			mx = array[i];
		}
	}

	print(array, n);
	std::cout << "------------" << std::endl;
	BubbleSort(array, n);
	std::cout << "------------" << std::endl;
	print(array, n);
	std::cout << "------------" << std::endl;
	std::cout << "Max:" << mx << std::endl;
	std::cout << "Summa:" << sm;
	return 0;
}