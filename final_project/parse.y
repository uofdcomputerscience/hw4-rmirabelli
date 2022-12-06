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
%token TOKEN_MODULO
%token TOKEN_SEMI
%token TOKEN_ERROR
%token TOKEN_LPAREN
%token TOKEN_RPAREN
%token TOKEN_PRINT
%token TOKEN_STRING
%token TOKEN_VAR
%token TOKEN_VARIABLE
%token TOKEN_LITERAL
%token TOKEN_ASSIGN
%token TOKEN_LBRACE
%token TOKEN_RBRACE
%token TOKEN_WHILE
%token TOKEN_IF
%token TOKEN_ELSE
%token TOKEN_LESSTHAN
%token TOKEN_GREATERTHAN
%token TOKEN_EQUALTO
%%

program: statements                  { parser_result = $1; }
	   ;

statements: statement				{ $$ = $1; append_statement($1); }
		  | statements statement	{ $$ = $1; append_statement($2); }
			;

statement: expr TOKEN_SEMI    		{ $$ = createStatement(ESK_EXPR, NULL, NULL, $1, NULL, NULL, NULL, NULL); } 
		 | TOKEN_PRINT TOKEN_LPAREN expr TOKEN_RPAREN TOKEN_SEMI { $$ = createPrintStatement( $3 ); }
		 | TOKEN_VAR expr TOKEN_SEMI { $$ = createDeclaration($2); }
		 | expr TOKEN_ASSIGN expr TOKEN_SEMI { $$ = createAssignment($1, $3);  }
		 | block							{ $$ = $1; }
		 | ifstatement						{ $$ = $1; }
		 | whileloop						{ $$ = $1; }
		 ;

block: TOKEN_LBRACE statements TOKEN_RBRACE { $$ = createBlock($2); }
	;

expr: expr TOKEN_PLUS term			{ $$ = createExpression(EXPR_ADD, $1, $3, NULL, NULL); }
	| expr TOKEN_MINUS term			{ $$ = createExpression(EXPR_MINUS, $1, $3, NULL, NULL); }
	| expr TOKEN_MODULO term		{ $$ = createExpression(EXPR_MODULO, $1, $3, NULL, NULL); }
	| TOKEN_STRING					{ $$ = createLiteral(scanned_text); }
	| TOKEN_LITERAL					{ $$ = createLiteral(scanned_text); }
	| TOKEN_VARIABLE				{ $$ = createVariable(scanned_text); }
	| term							{ $$ = $1; }
	;

ifstatement: TOKEN_IF predicateparen block { $$ = createIfStatement($2, $3); }
		   | TOKEN_IF predicateparen block TOKEN_ELSE block { $$ = createIfElseStatement($2, $3, $5); }
		   ;

whileloop: TOKEN_WHILE predicateparen block { $$ = createWhileStatement($2, $3); }
		 ;

predicateparen: TOKEN_LPAREN predicate TOKEN_RPAREN { $$ = $2; }
			  ;

predicate: expr TOKEN_LESSTHAN expr		{ $$ = createExpression(EXPR_LT, $1, $3, NULL, NULL); }
		 | expr TOKEN_GREATERTHAN expr	{ $$ = createExpression(EXPR_GT, $1, $3, NULL, NULL); }
		 | expr TOKEN_EQUALTO expr		{ $$ = createExpression(EXPR_ET, $1, $3, NULL, NULL); }
		 ;

term: term TOKEN_MULT factor        { $$ = createExpression(EXPR_MULT, $1, $3, NULL, NULL); }
	| factor						{ $$ = $1; }
	;

factor: TOKEN_INT					{ $$ = createValue(atoi(yytext)); }
	  ;

%%

