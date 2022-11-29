#include <stdio.h>
#include "expr.h"
#include "statement.h"
#include "util.h"

extern int yyparse();
extern Statement *parser_result;

int main(int argc, char **argv) {

	int rVal = yyparse();

	if (rVal == 0) {
		printf("parse success\n");
	} else {
		printf("parse fail\n");
	}

	Statement *cur = get_statements();
	while(cur) {
		printStatement(cur);
		printf("\n");
		cur = cur->next;
	}

	return rVal;

}
