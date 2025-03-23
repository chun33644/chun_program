#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {

	for (int idx = 0; idx < 9; ++idx) {
		for (int num = 0; num < 9; ++num) {
			printf("%d * %d = %d\n", idx, num, idx * num);
		}
		printf("---------\n");
	}

	return 0;
}
