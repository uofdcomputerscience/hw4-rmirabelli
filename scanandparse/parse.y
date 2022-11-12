%{

#include <stdio.h>
int yylex();
void yyerror(const char *s);

%}

%token TOKEN_INT
%token TOKEN_PLUS
%token TOKEN_MULT
%token TOKEN_SEMI
%token TOKEN_ERROR

%%

program: expr TOKEN_SEMI;

expr: expr TOKEN_PLUS term
	| term
	;

term: term TOKEN_MULT factor
	| factor
	;

factor: TOKEN_INT
	  ;

%%

