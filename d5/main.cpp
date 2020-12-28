#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>

#define ROWS 128
#define COLS 8

using namespace std;

int get_seat_id(string code);

int main() {
	std::vector<std::string> lines;
	std::cin.tie(0);
	std::string tmp = "";

	while (std::getline(std::cin, tmp)) {
		lines.push_back(tmp);
	}

	int max = 0;
	for (string code : lines) {
		int tmp = get_seat_id(code);
		if (tmp > max) max = tmp;
	}

	cout << max << endl;
}

int get_seat_id(string code) {
	// rows
	int i = 0;
	int row = ROWS-1;
	int divisor = ROWS;
	for (i; i < code.length()-3; i++) {
		divisor = divisor/2;
		std::cout << code[i];
		if (code[i] == 'F') row = row - divisor;
	}
	// cols
	int column = COLS-1;
	divisor = COLS;
	for (i; i < code.length(); i++) {
		divisor = divisor/2;
		if (code[i] == 'L') column = column - divisor;
	}
	return row * 8 + column;
}
