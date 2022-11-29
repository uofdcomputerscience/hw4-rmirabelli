%{

#include <stdio.h>
#include <stdlib.h>
#include "expr.h"
#include "scan.h"
#include "statement.h"
#include "util.h"

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
%token TOKEN_ARBITRARY
%token TOKEN_STRING
%token TOKEN_QUOTE
%%

program: statements                  { parser_result = $1; }
	   ;

statements
	: statement						{ $$ = $1; append_statement($1); }
	| statements statement			{ $$ = $2; append_statement($2); }
	;

statement: expr TOKEN_SEMI    		{ $$ = createStatement(ESK_EXPR, NULL, NULL, $1, NULL, NULL, NULL, NULL); } 
		 | TOKEN_PRINT TOKEN_LPAREN expr TOKEN_RPAREN TOKEN_SEMI { $$ = createPrintStatement( $3 ); }
		 ;

expr: expr TOKEN_PLUS term			{ $$ = createExpression(EXPR_ADD, $1, $3, NULL, NULL); }
	| expr TOKEN_MINUS term			{ $$ = createExpression(EXPR_MINUS, $1, $3, NULL, NULL); }
	| TOKEN_STRING                  { $$ = createLiteral(scanned_text); } 
	| term							{ $$ = $1; }
	;

term: term TOKEN_MULT factor        { $$ = createExpression(EXPR_MULT, $1, $3, NULL, NULL); }
	| factor						{ $$ = $1; }
	;

factor: TOKEN_INT					{ $$ = createValue(atoi(yytext)); }
	  ;

%%

