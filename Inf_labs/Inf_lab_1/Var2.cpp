#include <iostream>


int main() {
	setlocale(LC_ALL, "RUS");
	double fuel;

	std::cout << "Enter fuel:";
	std::cin >> fuel;

	if (fuel > 50.0) {
		std::cout << "Enough Fuel";
	}
	else if (fuel < 20.0) {
		std::cout << "Fuel is running out, refuel urgently!";
	}
	else {
		std::cout << "refueling recommended";
	}

	return 0;
}