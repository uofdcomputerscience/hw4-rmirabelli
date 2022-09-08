#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	const char *foo = "foo is a variable name we often use when we don't know what to say";
	const char *bar = "bar";

	char destination[16];

	int value = strncmp(foo, bar, 2);

	sprintf(destination, "%d", value);

	int fromString = atoi(destination);

	const char *f = "1.234";
	float fVal = atof(f);

	printf("%f\n", fVal);

	return 0;
}
