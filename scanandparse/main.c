#include <stdio.h>

extern int yyparse();

int main(int argc, char **argv) {

	int rVal = yyparse();

	if (rVal == 0) {
		printf("parse success\n");
	} else {
		printf("parse fail\n");
	}

	return rVal;

}
