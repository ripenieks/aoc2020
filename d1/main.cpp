#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>

int str2int(std::string str);

int main() {
	std::vector<int> numbers;

	std::string input;

	std::cin.tie(0);
	while (!std::cin.eof()) {
		std::cin >> input;
		numbers.push_back(str2int(input));
	}
	numbers.pop_back();
	//for (int x : numbers) {
	//	std::cout << x << std::endl;
	//}
	for (int x : numbers) {
		for (int y : numbers) {
			if (x + y == 2020) {
				printf("%d\n", x * y);
			}
		}
	}
	
	for (int x : numbers) {
		for (int y : numbers) {
			for (int z : numbers) {
				if (x + y + z == 2020) {
					printf("%d\n", x * y * z);
				}
			}
		}
	}
}

int str2int(std::string str) {
	int res = 0;
	for (int i = 0; i < str.length(); i++) {
		res = 10 * res + str[i] - '0';
	}
	return res;
}
