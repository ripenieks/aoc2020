#include <stdio.h>
#include <stdlib.h>

struct Input {
	size_t size;
	char *buf;
};

size_t read_input(char *buf);
int strtoint(char *snum);

int main() {
	FILE *fp;
	fp = fopen("input", "r");
	fseek(fp, 0, SEEK_END);
	size_t size = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	char buf[size];
	int n = fread(buf, size, sizeof(char), fp);
	fclose(fp);
	if (n < 0) {
		printf("bad fread\n");
		exit(-1);
	}
	buf[size] = 0;
	printf("%s\n", buf);

	char c = "";
	while (c != EOF)

}
