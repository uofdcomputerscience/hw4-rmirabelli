#ifndef __STATEMENT_H
#define __STATEMENT_H

#include "decl.h"
#include "expr.h"

typedef enum e_statementkind {
	ESK_DECL,
	ESK_EXPR,
	ESK_IFELSE,
	ESK_FOR,
	ESK_WHILE,
	ESK_PRINT,
	ESK_RETURN,
	ESK_BLOCK,
	ESK_ASSIGN,
} EStatementKind;

typedef struct t_statement {
	EStatementKind kind;
	struct t_decl*declaration;
	Expression *initial_expression;
	Expression *expression;
	Expression *next_expression;
	struct t_statement *body;
	struct t_statement *else_body;
	struct t_statement *next;
}Statement;

extern Statement *createStatement(EStatementKind kind, struct t_decl *declaration, Expression *initial_expression, Expression *expression, Expression *next_expression, Statement *body, Statement *else_body, Statement *next);

extern Statement *createPrintStatement(Expression *expression);
extern Statement *createDeclaration(Expression *expression);
extern Statement *createAssignment(Expression *lvalue, Expression *rvalue);
extern Statement *createBlock(Statement *statements);
extern Statement *createIfStatement(Expression *predicate, Statement *body);
extern Statement *createIfElseStatement(Expression *predicate, Statement *consequent, Statement *alternate);
extern Statement *createWhileStatement(Expression *predicate, Statement *body);

extern void printStatement(Statement *statement);
extern void printCodeForStatement(Statement *statement);

#endif // __STATEMENT_H
