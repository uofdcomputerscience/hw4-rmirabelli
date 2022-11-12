#include <stdio.h>
#include "expr.h"

extern int yyparse();
extern Expression *parser_result;

int main(int argc, char **argv) {

	int rVal = yyparse();

	if (rVal == 0) {
		printf("parse success\n");
	} else {
		printf("parse fail\n");
	}

	printf("parser result was %d\n", evaluateExpression(parser_result));

	return rVal;

}
