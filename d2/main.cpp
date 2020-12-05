#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>

int check_password_one(std::string str);
int check_password_two(std::string str);

int main() {
	std::vector<std::string> passwords;
	std::cin.tie(0);
	std::string tmp = "";

	while (std::getline(std::cin, tmp)) {
		passwords.push_back(tmp);
	}

	int valid_count = 0;
	for (std::string str : passwords) {
		valid_count = valid_count + check_password_one(str);
	}
	printf("%d\n", valid_count);

	valid_count = 0;
	for (std::string str : passwords) {
		valid_count = valid_count + check_password_two(str);
	}
	printf("%d\n", valid_count);
}

int check_password_one(std::string str) {
	int result = 0;
	int min = 0;
	int max = 0;
	std::string pass;
	char key;
// hacky garbage code inc	
	int it = 0;
	// get min val
	while (str[it] != '-') {
		min = min * 10 + str[it] - '0';
		it++;
	}
	// move iterator to skip the dash
	it++;
	while (str[it] != ' ') {
		max = max * 10 + str[it] - '0';
		it++;
	}
	// move iterator to skip the space
	it++;
	key = str[it];
	// move iterator to skip the space
	it++;
	int key_count = 0;
	while (str[it] && key_count <= max) {
		if (str[it] == key) {
			key_count++;
		}
		it++;
	}
	if (key_count >= min && key_count <= max) {
		result = 1;
	} else {
		result = 0;
	}

	//printf("min: %d, max: %d, key = %c, result: %d\n", min, max, key, result);

	return result;
}

int check_password_two(std::string str) {
	int result = 0;
	int pos1 = 0;
	int pos2 = 0;
	char key;
	int it = 0;
	// get min val
	while (str[it] != '-') {
		pos1 = pos1 * 10 + str[it] - '0';
		it++;
	}
	// move iterator to skip the dash
	it++;
	while (str[it] != ' ') {
		pos2 = pos2 * 10 + str[it] - '0';
		it++;
	}
	// move iterator to skip the space
	it++;
	key = str[it];
	// move iterator to skip the key, colon and the space
	it++;
	it++;
	it++;
	if (str[it + pos1 - 1] == key) {
		result = result ^ 1;
	}
	if (str[it + (pos2 - 1)] == key) {
		result = result ^ 1;
	}

	return result;	
}
