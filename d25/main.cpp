#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

#define SUBJECT 7

long long unsigned int transform(long long unsigned int value, long long unsigned int subject);
int find_loop_size(long int public_key);
int find_key(int pk1, int ls1, int pk2, int ls2);

int main() {
	std::cin.tie(0);
	long int pub_key1;
	long int pub_key2;
	std::cin >> pub_key1;
	std::cin >> pub_key2;

	int loop_size1 = find_loop_size(pub_key1);
	int loop_size2 = find_loop_size(pub_key2);

	std::cout << loop_size1	<< std::endl;
	std::cout << loop_size2 << std::endl;

	int enc_key = find_key(pub_key1, loop_size1, pub_key2, loop_size2);

	std::cout << enc_key << std::endl;
}

long long unsigned int transform(long long unsigned int value, long long unsigned int subject) {
	return (long long int)(value * subject) % 20201227;
}

int find_loop_size(long int public_key) {
	int loop_size = 0;
	int num = 1;
	while (num != public_key && loop_size < 100000000) {
		//std::cout << "num: " << num << " loop_size: " << loop_size << std::endl;
		num = transform(num, SUBJECT);
		loop_size++;
	}
	if (loop_size > 99999999) std::cout << "sadge" << std::endl;
	return loop_size;
}

int find_key(int pk1, int ls1, int pk2, int ls2) {
	long long int key1 = 1;
	for (int i = 0; i < ls1; i++) {
		key1 = transform(key1, pk2);
	}
	long long int key2 = 1;
	for (int i = 0; i < ls2; i++) {
		key2 = transform(key2, pk1);
	}
	std::cout << key1 << std::endl << key2 << std::endl;
	if (key1 == key2) return key1;
	else return -1;
}

