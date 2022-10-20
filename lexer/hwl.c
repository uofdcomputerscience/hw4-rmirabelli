#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum e_token {
	et_none,
	et_integer,
	et_lparen,
	et_rparen,
	et_add,
	et_multiply
} Token;

Token strToToken(char *str) {
	if (!strcmp(str, "(")) return et_lparen;
	if (!strcmp(str, ")")) return et_rparen;
	if (!strcmp(str, "+")) return et_add;
	if (!strcmp(str, "*")) return et_multiply;
	return et_integer;
}

int main(int argc, char **argv) {

	char parseMe[] = "( 3 + ( 4 * 5 ) )";
	Token tokens[256];
	memset(tokens, 0, sizeof(Token) * 256);

	char *tok = strtok(parseMe, " ");
	Token *pTokens = &tokens[0];

	while (tok) {
		*pTokens = strToToken(tok);
		++pTokens;
		tok = strtok(NULL, " ");
	}

	pTokens = &tokens[0];
	while (*pTokens) {
		printf("token value is %d\n", *pTokens);
		++pTokens;
	}

	return 0;

}
