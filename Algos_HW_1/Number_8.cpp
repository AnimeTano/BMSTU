#include <iostream>

int main() {
	char al;
	short n;
	short c = 0;

    std::cout << "Enter length:";
	std::cin >> n;

	for (short i = 0; i < n; i++) {
        std::cout << "Enter " << i + 1 << "char:";
		std::cin >> al;
		if (al == 'a' || al == 'e' || al == 'o' || al == 'i' || al == 'u' || al == 'y') {
			c += 1;
		}
	}

	std::cout << "Count:" << c;

	return 0;
}