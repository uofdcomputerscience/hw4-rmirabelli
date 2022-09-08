#include <stdio.h>

int main(int argc, char **argv) {

	int i;
	for (i = 1; i <= 100; ++i) {
		int didPrint = 0;
		if (i % 3 == 0) {
			printf("fizz");
			didPrint = 1;
		}
		if (i % 5 == 0) {
			printf("buzz");
			didPrint = 1;
		}
		if (!didPrint) {
			printf("%d", i);
		}
		printf("\n");
	}

	return 0;

}
