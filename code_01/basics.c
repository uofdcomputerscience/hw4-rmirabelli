#include <stdio.h>

int main(int argc, char **argv) {

	int i = 10000;
	while (i > 0) {
		switch (i) {
			case 9999: 
				printf("9999\n");
				break;
		}

		i--;
	}
foo:
	printf("%d is divisible evenly by both 3 and 7\n", i);

	return 0;

}
