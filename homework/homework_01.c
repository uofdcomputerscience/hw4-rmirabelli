#include <stdio.h>

void takesAPtr(int *ptr) {

	printf("We are printing a value of %d\n", *ptr);

}

int main(int argc, char **argv) {

	int val = 42;
	takesAPtr(&val);

}
