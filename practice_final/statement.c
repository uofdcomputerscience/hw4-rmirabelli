#include <stdlib.h>
#include <stdio.h>
#include "statement.h"
#include "expr.h"

Statement *createStatement(EStatementKind kind, Declaration *declaration, Expression *initial_expression, Expression *expression, Expression *next_expression, Statement *body, Statement *else_body, Statement *next) {

	Statement *node = malloc(sizeof(Statement));

	node->kind = kind;
	node->declaration = declaration;
	node->initial_expression = initial_expression;
	node->expression = expression;
	node->next_expression = next_expression;
	node->body = body;
	node->else_body = else_body;
	node->next = NULL;

	return node;

}

Statement *createPrintStatement(Expression *expression) {
	return createStatement(ESK_PRINT, NULL, NULL, expression, NULL, NULL, NULL, NULL);
}

void printStatement(Statement *statement) {
	printf("statement:");
	switch (statement->kind) {
		case ESK_PRINT:
			printf("print(");
			printExpression(statement->expression);
			printf(")");
			break;
		default:
			printExpression(statement->expression);
	}
}
