#include <iostream>

int main() {
	int age;

	std::cout << "Enter your age:";
	std::cin >> age;

	if (age < 18) {
		std::cout << "Age < 18";
	}
	else if (age > 60) {
		std::cout << "Age > 60";
	}
	else if (18 <= age <= 60) {
		std::cout << "age from 18 to 60";
	}

	return 0;
}