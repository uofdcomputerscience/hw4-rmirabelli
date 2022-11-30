#include <stdio.h>
#include <stdlib.h>
#include "expr.h"

Expression *createExpression(ExpressionType kind, Expression *left, Expression *right, const char *name, const char *literal) {

	Expression *expression = malloc(sizeof(Expression));

	expression->kind = kind;
	expression->left = left;
	expression->right = right;
	expression->value = 0;
	expression->literal = literal;
	expression->name = name;

	return expression;

}

Expression *createValue(int value) {

	Expression *expression = createExpression(EXPR_VALUE, NULL, NULL, NULL, NULL);
	
	expression->value = value;

	return expression;

}

Expression *createName(const char *name) {
	return createExpression(EXPR_NAME, NULL, NULL, name, NULL);
}

Expression *createLiteral(const char *literal) {
	return createExpression(EXPR_LITERAL, NULL, NULL, NULL, literal);
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
			return 0;
		case EXPR_LITERAL:
			return 0;
	}

	return 0;
}

void printExpressionFormatSpecifier(Expression *expression) {
	if (expression == NULL) return;

	switch(expression->kind) {
		case EXPR_LITERAL:
			printf("%%s");
			break;
		default:
			printf("%%d");
			break;
	}
}

void printExpression(Expression *expression) {

	if (expression == NULL) return;

	//printf("(");


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
			break;
	}

	printExpression(expression->right);

	//printf(")");
}
