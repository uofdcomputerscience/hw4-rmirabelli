#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// probably don't need all those includes, but whatever.
//

int main(int argc, char **argv) {

	if (argc != 3) {
	
		printf("Need exactly two arguments\n");
		return -1;
	}

	int second = atoi(argv[2]);
	int first = atoi(argv[1]);

	int sum = first + second;

	printf("the sum of %d and %d is %d\n", first, second, sum);

	return 0;

}
