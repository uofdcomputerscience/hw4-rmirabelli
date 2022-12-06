%{

#include "token.h"
#include "util.h"

%}

%%

[[:digit:]]+     { return TOKEN_INT; }
\+               { return TOKEN_PLUS; }
\-				 { return TOKEN_MINUS; }
\*               { return TOKEN_MULT; }
\%				 { return TOKEN_MODULO; }
\;               { return TOKEN_SEMI; }
[ \t\n]			 {}
\(				{ return TOKEN_LPAREN; }
\)				{ return TOKEN_RPAREN; }
print			{ return TOKEN_PRINT; }
\".*\"			{ append_scan(yytext); return TOKEN_STRING; }
var				{ return TOKEN_VAR; }
=				{ return TOKEN_ASSIGN; }
\{				{ return TOKEN_LBRACE; }
\}				{ return TOKEN_RBRACE; }
while			{ return TOKEN_WHILE; }
whilst			{ return TOKEN_WHILE; }
if				{ return TOKEN_IF; }
else			{ return TOKEN_ELSE; }
perchance		{ return TOKEN_IF; }
\<				{ return TOKEN_LESSTHAN; }
\>				{ return TOKEN_GREATERTHAN; }
==				{ return TOKEN_EQUALTO; }
"is equal to"		{ return TOKEN_EQUALTO; }
[[:alpha:]]		{ append_scan(yytext); return TOKEN_VARIABLE; }
.                { return TOKEN_ERROR; }

%%
