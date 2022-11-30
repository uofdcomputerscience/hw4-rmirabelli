#include <stdio.h>
#include "expr.h"
#include "statement.h"
#include "util.h"

extern int yyparse();
extern Statement *parser_result;

void printPreamble() {
	printf("#include <stdio.h>\n");
	printf("int main(int argc, char **argv) {\n");
}

void printPostamble() {

	printf("}\n");

}

int main(int argc, char **argv) {

	int rVal = yyparse();
		
	if (rVal == 0) {
		printPreamble();
		Statement *cur = get_statements();
		while(cur) {
			printf("\t");
			printCodeForStatement(cur);
			printf("\n");
			cur = cur->next;
		}
		printPostamble();
	} else {
		printf("parse fail\n");
	}

	return rVal;

}
