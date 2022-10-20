%{

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

%}

%%

int						{ printf("type: integer\n"); } 
\(						{ printf("lparen\n"); }
\)						{ printf("rparen\n"); }
\{						{ printf("lbrace\n"); }
\}						{ printf("rbrace\n"); }
\[						{ printf("lbracket\n"); }
\]						{ printf("rbracket\n"); }
[\,\;]					{ printf("separator\n"); }
\*						{ printf("multiply\n"); }
\+						{ printf("addition\n"); }
return					{ printf("keyword: return\n"); }
[ \n\t]					{}
[[:digit:]]+			{ printf("integer value: %d\n", atoi(yytext)); }
[[:alpha:]]+			{ printf("identifier %s\n", yytext); }

%%

int main(int argc, char ** argv) {

	yylex();

	return 0;

}
