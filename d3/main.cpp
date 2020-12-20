#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>

std::vector<int> count_trees(std::vector<std::string> field);

int main() {
	std::vector<std::string> field;
	std::cin.tie(0);
	std::string tmp = "";

	while (std::getline(std::cin, tmp)) {
		field.push_back(tmp);
	}
	std::vector<int> res = count_trees(field);
	long int product = 1;
	for (int x : res) {
		//std::cout << x << std::endl;
		product = product * x;
	}
	std::cout << res[1] << std::endl;
	std::cout << product << std::endl;
}

std::vector<int> count_trees(std::vector<std::string> field) {
	int vx[] = {1,3,5,7,1};
	int vy[] = {1,1,1,1,2};

	std::vector<int> total_trees;
	for (int i = 0; i < sizeof(vx) / sizeof(vx[0]); i++) {
		int y = 0;
		int x = 0;
		int trees = 0;
		//printf("vx: %d, vy: %d\n", vx[i],vy[y]);
		while (y < field.size()) {
			if (field[y][x] == '#') trees++;
			y = y + vy[i];
			x = (x + vx[i]) % field[0].length();
		}
		total_trees.push_back(trees);
	}
	return total_trees;
}
