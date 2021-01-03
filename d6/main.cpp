#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <set>

void parse_inputs(const std::vector<std::string> &input, std::vector<std::string> &entries) {
	std::string tmp;
	for (std::string str : input) {
		if (str != "") {
			tmp = tmp + str + " ";
		} else {
			tmp.pop_back();
			entries.push_back(tmp);
			tmp = "";
		}
	}
}

int count_answers(const std::string &entries) {
	std::set<char> uniques;
	for (std::string::const_iterator it = entries.begin(); it != entries.end(); it++) {
		if (*it == ' ') continue;
		uniques.insert(*it);
	}
	return uniques.size();
}

int main() {
	std::vector<std::string> lines;
	std::cin.tie(0);
	std::string tmp = "";

	while (std::getline(std::cin, tmp)) {
		lines.push_back(tmp);
	}
	std::vector<std::string> entries;

	parse_inputs(lines, entries);

	int sum = 0;
	for (std::string str : entries) {
		sum = sum + count_answers(str);
	}
	std::cout << sum << std::endl;
}
