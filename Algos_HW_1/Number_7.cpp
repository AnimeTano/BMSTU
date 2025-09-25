#include <iostream>

int main() {
	int n;

	std::cout << "Enter n:";
	std::cin >> n;

	for (int i = 1; i < n; i++) {
		std::cout << i * i << std::endl;
	}

    return 0;
}