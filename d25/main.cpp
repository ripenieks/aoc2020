#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

#define SUBJECT 7
#define MAX_ITER 100000000

long int transform(long int value, long int subject);
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

long int transform(long int value, long int subject) {
	return (value * subject) % 20201227;
}

int find_loop_size(long int public_key) {
	int loop_size = 0;
	int num = 1;
	while (num != public_key && loop_size < MAX_ITER) {
		//std::cout << "num: " << num << " loop_size: " << loop_size << std::endl;
		num = transform(num, SUBJECT);
		loop_size++;
	}
	if (loop_size > MAX_ITER-1) std::cout << "sadge" << std::endl;
	return loop_size;
}

int find_key(int pk1, int ls1, int pk2, int ls2) {
	long int key1 = 1;
	for (int i = 0; i < ls1; i++) {
		key1 = transform(key1, pk2);
	}
	long int key2 = 1;
	for (int i = 0; i < ls2; i++) {
		key2 = transform(key2, pk1);
	}
	if (key1 == key2) return key1;
	else return -1;
}

