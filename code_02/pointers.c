#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void takesAnIntPtr(int *pointer) {
	

}

int main(int argc, char **argv) {

	int value = 42;
	int *ptr = &value;

	printf("the address of value is 0x%lx\n", (long int)ptr);
	printf("the value of value is %d", *ptr);

	return 0;

}
