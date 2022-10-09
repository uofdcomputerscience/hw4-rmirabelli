#include <stdio.h>
#include "token_type.h"
#include "parser_helpers.h"
#include "recursive_descent.h"

int main(int argc, char **argv) {

	Token buf[] = {TOKEN_IDENTIFIER, TOKEN_IDENTIFIER, TOKEN_EOF};
	setupTokenBuffer(buf, sizeof(buf)/sizeof(buf[0]));
	int rVal = parse_P();
	cleanupTokenBuffer();

	printf("parsing the tokens gave a result of %d\n", rVal);

	return !rVal;

}
