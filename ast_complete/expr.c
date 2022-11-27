#include <stdio.h>
#include <stdlib.h>
#include "expr.h"

Expression *createExpression(ExpressionType kind, Expression *left, Expression *right) {

	Expression *expression = malloc(sizeof(Expression));

	expression->kind = kind;
	expression->left = left;
	expression->right = right;
	expression->value = 0;
	expression->name = NULL;
	expression->literal = NULL;

	return expression;

}

Expression *createValue(int value) {

	Expression *expression = createExpression(EXPR_VALUE, NULL, NULL);
	
	expression->value = value;

	return expression;

}

Expression *createName(const char *name) {

	Expression *expression = createExpression(EXPR_NAME, NULL, NULL);
	
	expression->name = name;
	
	return expression;

}

Expression *createLiteral(const char *literal) {

	Expression *expression = createExpression(EXPR_LITERAL, NULL, NULL);

	expression->literal = literal;

	return expression;

}

int evaluateExpression(Expression *expression) {

	if (expression == NULL) return 0;

	int left = evaluateExpression(expression->left);
	int right = evaluateExpression(expression->right);

	switch(expression->kind) {
		case EXPR_ADD:
			return left + right;
		case EXPR_MINUS:
			return left - right;
		case EXPR_MULT:
			return left * right;
		case EXPR_VALUE:
			return expression->value;
		case EXPR_NAME:
		case EXPR_LITERAL:
			return 0;
	}

	return 0;
}

void printExpression(Expression *expression) {

	if (expression == NULL) return;

	printf("(");


	printExpression(expression->left);

	switch(expression->kind) {
		case EXPR_ADD:
			printf("+");
			break;
		case EXPR_MINUS:
			printf("-");
			break;
		case EXPR_MULT:
			printf("*");
			break;
		case EXPR_VALUE:
			printf("%d", expression->value);
			break;
		case EXPR_NAME:
			printf("%s", expression->name);
			break;
		case EXPR_LITERAL:
			printf("%s", expression->literal);
	}

	printExpression(expression->right);

	printf(")");
}
