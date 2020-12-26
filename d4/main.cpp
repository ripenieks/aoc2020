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
	std::string ecl;
	std::string pid;
	std::string cid;
public:
	Passport(std::string raw_pass);
	int Validate();
	void Print();
	int valid = 0;
};

// parses the passport string into a fancy structure
Passport::Passport(std::string raw_pass) {
	int i = 0;
	std::vector<std::string> keys = {"byr", "iyr", "eyr", "hgt", "hcl", "pid", "cid"};
	while (i < raw_pass.length()) {
		std::string *key_ptr= nullptr;
		std::string key;
		for (int key_length = 0; key_length < 3; key_length++) {
			key.push_back(raw_pass[i]);
			i++;
		}
		if (key == "byr") {
			key_ptr = &byr;
		}
		if (key == "iyr") {
			key_ptr = &iyr;
		}
		if (key == "eyr") {
			key_ptr = &eyr;
		}
		if (key == "hgt") {
			key_ptr = &hgt;
		}
		if (key == "hcl") {
			key_ptr = &hcl;
		}
		if (key == "ecl") {
			key_ptr = &ecl;
		}
		if (key == "pid") {
			key_ptr = &pid;
		}
		if (key == "cid") {
			key_ptr = &cid;
		}
		i++;
		do {
			key_ptr->push_back(raw_pass[i]);
			i++;
		}
		while (i < raw_pass.length() && raw_pass.at(i) != ' ');
		i++;
	}
}

// does all the validation garbage
int Passport::Validate() {
	// generic number value
	int num;
	// generic iterator
	int i;

	//validate byr
	if (byr.empty()) return 0;
	num = 0;
	i = 0;
	while (byr[i] >= '0' && byr[i] <= '9') {
		num = num * 10 + (byr[i] - '0');
		i++;
	}
	if (num < 1920 || num > 2002) return 0;

	//validate iyr
	if (iyr.empty()) return 0;
	num = 0;
	i = 0;
	while (iyr[i] >= '0' && iyr[i] <= '9') {
		num = num * 10 + (iyr[i] - '0');
		i++;
	}
	if (num < 2010 || num > 2020) return 0;

	//validate eyr
	if (eyr.empty()) return 0;
	num = 0;
	i = 0;
	while (eyr[i] >= '0' && eyr[i] <= '9') {
		num = num * 10 + (eyr[i] - '0');
		i++;
	}
	if (num < 2020 || num > 2030) return 0;

	// validate hgt
	if (hgt.empty()) return 0;
	num = 0;
	i = 0;
	while (hgt[i] >= '0' && hgt[i] <= '9') {
		num = num * 10 + (hgt[i] - '0');
		i++;
	}
	std::string unit = std::string(hgt, i);
	if (unit == "cm") {
		if (num < 150 || num > 193) return 0;	
	}
	else if (unit == "in") {
		if (num < 59 || num > 76) return 0;
	}
	else return 0;

	// validate hcl
	if (hcl.empty()) return 0;
	num = 0;
	i = 0;
	if (hcl[0] != '#') return 0;
	i++;
	while ((hcl[i] >= '0' && hcl[i] <= '9') || (hcl[i] >= 'a' && hcl[i] <= 'f')) {
		num++;
		i++;
	}
	if (num != 6) return 0;

	// validate ecl
	if (ecl.empty()) return 0;
	std::set<std::string> good_ecls = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
	i = 0;
	if (good_ecls.find(ecl) == good_ecls.end()) return 0;

    // validate pid
	if (pid.empty()) return 0;
	i = 0;
	while (pid[i] >= '0' && pid[i] <= '9') {
		i++;
	}
	if (i != 9) return 0;

	return 1;
}

void Passport::Print() {
	std::cout << "PASSPORT" << std::endl;
	std::cout << "byr: " << byr << std::endl;
	std::cout << "iyr: " << iyr << std::endl;
	std::cout << "eyr: " << eyr << std::endl;
	std::cout << "hgt: " << hgt << std::endl;
	std::cout << "hcl: " << hcl << std::endl;
	std::cout << "ecl: " << ecl << std::endl;
	std::cout << "pid: " << pid << std::endl;
	std::cout << "cid: " << cid << std::endl;
	std::cout << "valid: " << valid << std::endl;
}

void parse_passports(const std::vector<std::string> input, std::vector<std::string> &passports);

int main() {
	std::vector<std::string> lines;
	std::cin.tie(0);
	std::string tmp = "";

	while (std::getline(std::cin, tmp)) {
		lines.push_back(tmp);
	}

	std::vector<std::string> raw_passports;
	parse_passports(lines, raw_passports);
	std::vector<Passport> passports;

	int valid_passports = 0;
	for (std::string str : raw_passports) {
		Passport passport(str);
		valid_passports = valid_passports + passport.Validate();
		//passport.Print();
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
