#include <iostream>

int main() {
	float celc;

	std::cout << "Enter celc:";
	std::cin >> celc;
	
	float faren = celc * (9.0 / 5.0) + 32;
	std::cout << "Farengeit" << faren;

	return 0;
}