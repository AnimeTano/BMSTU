#include <iostream>


int main() {
	int sm;
	std::cout << "Enter length in sm:";
	std::cin >> sm;

	std::cout << "Metres:" << sm / 100 << std::endl;
	std::cout << "Sm:" << sm % 100;

	return 0;
}