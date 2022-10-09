#include "token_type.h"
#include "parser_helpers.h"

extern int parse_E();

int parse_F() {
	// can be (E) -or- an identifer
	Token t = scanToken();
	if (t == TOKEN_LEFT_PAREN) {
		return parse_E() && expectToken(TOKEN_RIGHT_PAREN);
	} else if (t == TOKEN_IDENTIFIER) {
		return 1;
	} else {
		// ERROR CONDITION: CONSIDER PRINTING AN ERROR
	}
	return 0;
}

int parse_T_prime() {
	Token t = scanToken();
	if (t == TOKEN_MULTIPLY) {
		return parse_F() && parse_T_prime();
	} else {
		putBackToken(t);
	}
	return 1;
}

int parse_T() {
	return parse_F() && parse_T_prime();
}

int parse_E_prime() {
	Token t = scanToken();
	if (t == TOKEN_PLUS) {
		return parse_T() && parse_E_prime();
	} else {
		putBackToken(t);
	}
	return 1;
}

int parse_E() {
	return parse_T() && parse_E_prime();
}

int parse_P() {
	// Assumes parser has been set up
	return parse_E() && expectToken(TOKEN_EOF);
}
