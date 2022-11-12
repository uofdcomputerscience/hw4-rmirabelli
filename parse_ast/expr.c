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
		case EXPR_MULT:
			return left * right;
		case EXPR_VALUE:
			return expression->value;
	}

	return 0;
}
