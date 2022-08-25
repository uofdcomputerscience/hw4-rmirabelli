#include <stdio.h>

int isOdd(int number) {
	return number & 0x1;
}

int isOddKindaSlow(int number) {
	return number % 2;
}

int isOddInAnotherBadWay(int number) {
	switch(number) {
		case 1:
		case 3:
		case 5:
		case 7: return 1;
		case 2:
		case 4:
		case 6:
		case 8: return 0;
		default: return 0;
	}
}

int isOddInABadWay(int number) {
	if (number == 1) return 1;
	if (number == 2) return 0;
	if (number == 3) return 1;
	if (number == 4) return 0;

	return 0;
}

int main(int argc, char** argv) {
	int number = 31;
	char *string = isOdd(number) ? "odd" : "even";
	printf("the number %d is %s\n", number, string);
	return 0;
}
