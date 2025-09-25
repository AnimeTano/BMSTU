#include <iostream>

int main() {
	setlocale(LC_ALL, "RUS");
	double fuels = 0;

	while (fuels >= 0.0) {
		std::cout << "Enter your level of fuel:";
		std::cin >> fuels;
	}
	std::cout << fuels << " litres of fuel";
	return 0;
}