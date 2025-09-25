#include <iostream>

int main() {
	int number;
	
	std::cout << "Enter your number:";
	std::cin >> number;

	if (number % 2 == 0) {
		std::cout << "Chet";
	}
	else {
		std::cout << "Nechet";
	}

	return 0;
}