%{

#include <stdio.h>
#include <stdlib.h>
#include "expr.h"
#include "scan.h"

int yylex();
void yyerror(const char *s);

#define YYSTYPE Expression*

Expression *parser_result = NULL;

%}

%token TOKEN_INT
%token TOKEN_PLUS
%token TOKEN_MULT
%token TOKEN_SEMI
%token TOKEN_ERROR

%%

program: expr TOKEN_SEMI			{ parser_result = $1; }
	   ;

expr: expr TOKEN_PLUS term			{ $$ = createExpression(EXPR_ADD, $1, $3); }
	| term							{ $$ = $1; }
	;

term: term TOKEN_MULT factor        { $$ = createExpression(EXPR_MULT, $1, $3); }
	| factor						{ $$ = $1; }
	;

factor: TOKEN_INT					{ $$ = createValue(atoi(yytext)); }
	  ;

%%

