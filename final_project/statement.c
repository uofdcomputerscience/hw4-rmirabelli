#include <stdlib.h>
#include <stdio.h>
#include "statement.h"
#include "expr.h"
#include "util.h"

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

Statement *createWhileStatement(Expression *predicate, Statement *body) {
	remove_statements(body);
	return createStatement(ESK_WHILE, NULL, NULL, predicate, NULL, body, NULL, NULL);
}

Statement *createIfElseStatement(Expression *predicate, Statement *consequent, Statement *alternate) {
	remove_statements(consequent);
	remove_statements(alternate);
	return createStatement(ESK_IFELSE, NULL, NULL, predicate, NULL, consequent, alternate, NULL);
}

Statement *createIfStatement(Expression *predicate, Statement *body) {
	remove_statements(body);
	return createStatement(ESK_IFELSE, NULL, NULL, predicate, NULL, body, NULL, NULL);
}

Statement *createBlock(Statement *statements) {
	remove_statements(statements);
	return createStatement(ESK_BLOCK, NULL, NULL, NULL, NULL, statements, NULL, NULL);
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
		case ESK_BLOCK:
			printf("{\n");
			Statement *statements = statement->body;
			while(statements) {
				printf("\t\t");
				printCodeForStatement(statements);
				statements = statements->next;
			}
			printf("\t}\n");
			break;
		case ESK_IFELSE:
			printf("if (");
			printExpression(statement->expression);
			printf(") ");
			printCodeForStatement(statement->body);
			if (statement->else_body) {
				printf("\telse\t");
				printCodeForStatement(statement->else_body);
			}
			printf("\n");
			break;
		case ESK_WHILE:
			printf("while(");
			printExpression(statement->expression);
			printf(")\n");
			printCodeForStatement(statement->body);
			break;
		default:
			printExpression(statement->expression);
	}
}
