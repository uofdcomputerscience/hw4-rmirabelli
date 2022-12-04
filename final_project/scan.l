%{

#include "token.h"
#include "util.h"

%}

%%

[[:digit:]]+     { return TOKEN_INT; }
\+               { return TOKEN_PLUS; }
\-				 { return TOKEN_MINUS; }
\*               { return TOKEN_MULT; }
\;               { return TOKEN_SEMI; }
[ \t\n]			 {}
\(				{ return TOKEN_LPAREN; }
\)				{ return TOKEN_RPAREN; }
print			{ return TOKEN_PRINT; }
\".*\"			{ append_scan(yytext); return TOKEN_STRING; }
var				{ return TOKEN_VAR; }
=				{ return TOKEN_ASSIGN; }
[[:alpha:]]		{ append_scan(yytext); return TOKEN_VARIABLE; }
.                { return TOKEN_ERROR; }

%%
