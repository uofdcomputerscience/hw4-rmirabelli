%{

#include "token.h"

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
.                { return TOKEN_ERROR; }


%%
