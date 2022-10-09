#include <stdlib.h>
#include <string.h>
#include "parser_helpers.h"
#include "token_type.h"

static Token *token_buffer; // allocated memory
static Token *current_token;// working ptr

void setupTokenBuffer(Token *srcTokenBuffer, int count) {
	token_buffer = (Token *)malloc(count * sizeof(Token));
	memcpy(token_buffer, srcTokenBuffer, count * sizeof(Token));
	current_token = token_buffer;
}

void cleanupTokenBuffer() {
	free(token_buffer);
	token_buffer = NULL;
	current_token = NULL;
}

Token scanToken() {
	/* get current token, and advance pointer for future use */
	Token t = *current_token;
	current_token++;
	return t;
}

void putBackToken(Token t) {
	/* move the pointer back a step, and then set the value of its contents */
	--current_token;
	*current_token = t;
}

int expectToken(Token t) {
	/* check if the current token matches. If it does, advance and return true */
	if (*current_token == t) {
		++current_token;
		return 1;
	}
	return 0;
}

