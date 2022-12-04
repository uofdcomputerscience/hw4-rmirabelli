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

Statement *createDeclaration(Expression *expression) {
	return createStatement(ESK_DECL, NULL, NULL, expression, NULL, NULL, NULL, NULL);
}

Statement *createAssignment(Expression *lvalue, Expression *rvalue) {
	return createStatement(ESK_ASSIGN, NULL, NULL, lvalue, rvalue, NULL, NULL, NULL);
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
			printf("\n)");
			break;
		default:
			printExpression(statement->expression);
	}
}

void printCodeForStatement(Statement *statement) {
	switch(statement->kind) {
		case ESK_PRINT:
			printf("printf(\"");
			printExpressionFormatSpecifier(statement->expression);
			printf("\\n\", ");
			printExpression(statement->expression);
			printf(");\n");
			break;
		case ESK_DECL:
			printf("int ");
			printExpression(statement->expression);
			printf(" = 0;\n");
			break;
		case ESK_ASSIGN:
			printExpression(statement->expression);
			printf(" = ");
			printExpression(statement->next_expression);
			printf(";\n");
			break;
		default:
			printExpression(statement->expression);
	}
}
