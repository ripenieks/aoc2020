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
	int min = 1000;
	vector<int> ids;
	for (string code : lines) {
		int tmp = get_seat_id(code);
		ids.push_back(tmp);
	//	cout << tmp << endl;
		if (tmp > max) max = tmp;
		if (tmp < min) min = tmp;
	}
	int min_row = min / 8;
	int max_row = max / 8;

	int sum_all = 0;
	for (int i = min_row+1; i < max_row; i++) {
		for (int j = 0; j < 8; j++) {
			sum_all = sum_all + (i * 8 + j);
		}
	}

	int sum_actual = 0;
	// exclude first and last row from the list
	min = ((min_row + 1) * 8) - 1;
	max = (max_row) * 8;
	for (int i : ids) {
		if (i > min && i < max) sum_actual = sum_actual + i;	
	}
	cout << sum_all - sum_actual << endl;
}

int get_seat_id(string code) {
	// rows
	int i = 0;
	int row = ROWS-1;
	int divisor = ROWS;
	for (i; i < code.length()-3; i++) {
		divisor = divisor/2;
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

	
