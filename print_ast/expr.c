#include <stdio.h>
#include <stdlib.h>
#include "expr.h"

Expression *createExpression(ExpressionType kind, Expression *left, Expression *right) {

	Expression *expression = malloc(sizeof(Expression));

	expression->kind = kind;
	expression->left = left;
	expression->right = right;
	expression->value = 0;

	return expression;

}

Expression *createValue(int value) {

	Expression *expression = createExpression(EXPR_VALUE, NULL, NULL);
	
	expression->value = value;

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
	}

	printExpression(expression->right);

	printf(")");
}
