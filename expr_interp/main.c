#include <stdio.h>

extern int yyparse();
extern int parser_result;

int main(int argc, char **argv) {

	int rVal = yyparse();

	if (rVal == 0) {
		printf("parse success\n");
	} else {
		printf("parse fail\n");
	}

	printf("parser result was %d\n", parser_result);

	return rVal;

}
