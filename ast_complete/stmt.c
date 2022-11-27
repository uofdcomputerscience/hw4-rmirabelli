#include <stdio.h>
#include <stdlib.h>

#include "stmt.h"
#include "expr.h"

void printStatement(Statement *statement) {

	if (statement == NULL) return;

	switch(statement->kind) {
		case ESK_EXPR:
			printExpression(statement->expression);
			break;
		case ESK_PRINT:
//			printf("print the following:");
//			printExpression(statement->expression);
//			printf("\n");
			printf("printf(\"\%s\"");
		   	printExpression(statement->expression);
			printf(")\n");
			break;
		default:
			break;
	}

}

Statement *createStatement(EStatementKind kind, struct t_decl *declaration, Expression *initial_expression, Expression *expression, Expression *next_expression, Statement *body, Statement *else_body, Statement *next) {

	Statement *node = malloc(sizeof(Statement));

	node->kind = kind;
	node->declaration = declaration;
	node->initial_expression = initial_expression;
	node->expression = expression;
	node->next_expression = next_expression;
	node->body = body;
	node->else_body = body;
	node->next = next;

	return node;

}

Statement *createExpressionStatement(Expression *expression) {

	return createStatement(ESK_EXPR, NULL, NULL, expression, NULL, NULL, NULL, NULL);

}

Statement *createPrintStatement(Expression *expression) {

	return createStatement(ESK_PRINT, NULL, NULL, expression, NULL, NULL, NULL, NULL);

}

