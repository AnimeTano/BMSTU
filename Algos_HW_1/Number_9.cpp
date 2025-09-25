#include <iostream>

int main() {
	int n;
	int sm = 0;

    std::cout << "Enter n:";
	std::cin >> n;

	for (int i = 1; i < n; i++) {
		if (i % 2 == 0 || i % 5 == 0) {
			sm += i;
		}
	}

	std::cout << "Summa:" << sm;

	return 0;
}