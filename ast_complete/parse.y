%{

#include <stdio.h>
#include <stdlib.h>
#include "expr.h"
#include "stmt.h"
#include "scan.h"

int yylex();
void yyerror(const char *s);

#define YYSTYPE void*

Statement *parser_result = NULL;

%}

%token TOKEN_INT
%token TOKEN_PLUS
%token TOKEN_MINUS
%token TOKEN_MULT
%token TOKEN_SEMI
%token TOKEN_ERROR
%token TOKEN_LPAREN
%token TOKEN_RPAREN
%token TOKEN_PRINT

%%

program: statement					{ parser_result = $1; }
	   ;

statement: expr TOKEN_SEMI			{ $$ = createExpressionStatement($1); }
		 | TOKEN_PRINT TOKEN_LPAREN expr TOKEN_RPAREN TOKEN_SEMI { $$ = createPrintStatement($3); }
		 ;

expr: expr TOKEN_PLUS term			{ $$ = createExpression(EXPR_ADD, $1, $3); }
	| expr TOKEN_MINUS term			{ $$ = createExpression(EXPR_MINUS, $1, $3); }
	| term							{ $$ = $1; }
	;

term: term TOKEN_MULT factor        { $$ = createExpression(EXPR_MULT, $1, $3); }
	| factor						{ $$ = $1; }
	;

factor: TOKEN_INT					{ $$ = createValue(atoi(yytext)); }
	  ;

%%

