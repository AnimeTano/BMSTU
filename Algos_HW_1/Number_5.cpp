#include <iostream>

int main() {
	int number;

	std::cout << "Enter number:";
	std::cin >> number;

	if (number % 5 == 0 && number % 3 == 0){
		std::cout << "kr 5 and kr 3";
	}
	else if(number % 3 == 0){
		std::cout << "kr 3";
	}
	else if (number % 5 == 0){
		std::cout << "Kr 5";
	}
	else {
		std::cout << "Not kr";
	}

	return 0;
}