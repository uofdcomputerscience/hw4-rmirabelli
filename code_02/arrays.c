#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {

	char buf[64];

	int numbers[] = { 0, 1, 2, 3, 4 };
	int index = 3;
	numbers[index] = 77;

	printf("The 3rd element in numbers is %d", numbers[index]);

	char *strings[] = {
		"foo",
		"bar",
		"baz",
		"other made up words",
		"snoot"
	};

	printf("The numbers array is %d in size\n", sizeof(numbers)/sizeof(numbers[0]));

	return numbers[0];

}
