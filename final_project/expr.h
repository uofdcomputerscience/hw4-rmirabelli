#ifndef __EXPR_H
#define __EXPR_H

typedef enum e_expr {
	EXPR_ADD,
	EXPR_MINUS,
	EXPR_MULT,
	EXPR_NAME,
	EXPR_VALUE,
	EXPR_LITERAL,
} ExpressionType;

typedef struct s_expr {
	ExpressionType kind;
	struct s_expr *left;
	struct s_expr *right;
	int value;
	const char *name;
	const char *literal;
} Expression;

extern Expression *createExpression(ExpressionType type, Expression *left, Expression *right, const char *name, const char *literal);
extern Expression *createValue(int value);
extern int evaluateExpression(Expression *expreesion);
extern void printExpression(Expression *expression);
extern Expression *createName(const char *name);
extern Expression *createLiteral(const char *literal);
extern void printExpressionFormatSpecifier(Expression *expression);
#endif // __EXPR_H
