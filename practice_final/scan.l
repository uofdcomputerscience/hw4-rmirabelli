%{

#include "token.h"
#include "util.h"
// 
//[[:alpha:]|[:digit:]]+ { return TOKEN_ARBITRARY; }
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
\".*\"          { append_scan(yytext); return TOKEN_STRING; }
\"				{ return TOKEN_QUOTE; }

%%
