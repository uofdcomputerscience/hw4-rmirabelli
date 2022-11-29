#include <stdio.h>
#include "expr.h"
#include "statement.h"

extern int yyparse();
extern Statement *parser_result;

int main(int argc, char **argv) {

	int rVal = yyparse();

	if (rVal == 0) {
		printf("parse success\n");
	} else {
		printf("parse fail\n");
	}
	
	printStatement(parser_result);
	printf("\n");

	return rVal;

}
