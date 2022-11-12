%{

#include <stdio.h>
#include <stdlib.h>
#include "scan.h"

int yylex();
void yyerror(const char *s);

int parser_result;

%}

%token TOKEN_INT
%token TOKEN_PLUS
%token TOKEN_MULT
%token TOKEN_SEMI
%token TOKEN_ERROR

%%

program: expr TOKEN_SEMI			{ parser_result = $1; }
	   ;

expr: expr TOKEN_PLUS term			{ $$ = $1 + $3; }
	| term							{ $$ = $1; }
	;

term: term TOKEN_MULT factor        { $$ = $1 * $3; }
	| factor						{ $$ = $1; }
	;

factor: TOKEN_INT					{ $$ = atoi(yytext); }
	  ;

%%

