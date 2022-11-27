%{

#include "token.h"

%}

%%

[[:digit:]]+     { return TOKEN_INT; }
\+               { return TOKEN_PLUS; }
\-				 { return TOKEN_MINUS; }
\*               { return TOKEN_MULT; }
\;               { return TOKEN_SEMI; }
print			 { return TOKEN_PRINT; }
\(				 { return TOKEN_LPAREN; }
\)				 { return TOKEN_RPAREN; }
[ \t\n]			 {}
.                { return TOKEN_ERROR; }


%%
