#include <iostream>


int main() {
	int length;
	int width;

	std::cout << "Enter length:" << std::endl;
    std::cin >> length;

	std::cout << "Enter width:" << std::endl;
    std::cin >> width;

	std::cout << "Square:" << (length * width);

	return 0;
}