#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <set>

class Passport {
private:
	std::string byr;
	std::string iyr;
	std::string eyr;
	std::string hgt;
	std::string hcl;
	std::string pid;
	std::string cid;
public:
	Passport(std::string raw_pass);
	void Validate();
	int valid = 1;
};

Passport::Passport(std::string raw_pass) {
	
}

void Passport::Validate() {
		
}

void parse_passports(const std::vector<std::string> input, std::vector<std::string> &passports);
int validate_passport(std::string pass);

int main() {
	std::vector<std::string> lines;
	std::cin.tie(0);
	std::string tmp = "";

	while (std::getline(std::cin, tmp)) {
		lines.push_back(tmp);
	}

	std::vector<std::string> passports;
	parse_passports(lines, passports);

	int valid_passports = 0;
	for (std::string str : passports) {
		valid_passports = valid_passports + validate_passport(str);
	}
	printf("%d\n", valid_passports);
}

void parse_passports(const std::vector<std::string> input, std::vector<std::string> &passports) {
	std::string tmp;
	for (std::string str : input) {
		if (str != "") {
			tmp = tmp + str + " ";
		} else {
			tmp.pop_back();
			passports.push_back(tmp);
			tmp = "";
		}
	}
}

int validate_passport(std::string pass) {
	int i = 0;
	int field_count = 0;
	std::vector<std::string> fields;
	while (i < pass.length()) {
		std::string key;
		for (int key_length = 0; key_length < 3; key_length++) {
			key.push_back(pass[i]);
			i++;
		}
		// cid optional
		if (key != "cid")
			fields.push_back(key);

		// pass the iterator to next field
		do {
			i++;
		}
		while (i < pass.length() && pass.at(i) != ' ');
		i++;
	}  
	if (fields.size() != 7)
		return 0;
	else return 1;
}       
        
        
