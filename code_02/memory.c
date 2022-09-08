#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int foo() {
	int *a = malloc(1024);
	free(a);
	return 0;
}

int main(int argc, char **argv) {

	int numbers[] = {1,2,3};

	int count = 64;
	int *ptr = malloc(sizeof(int)*count);

	memset(ptr, 0, sizeof(int)*count);

	for (int i = 0; i < 3; ++i) {
		ptr[i] = numbers[i];
	}

	for (int i = 0; i < 1024; ++i) {
		foo();
	}

	memcpy(ptr, numbers, sizeof(numbers));

	free(ptr);
	
	printf("the second element is %d", ptr[2]);


	return 0;
}
