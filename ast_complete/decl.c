#include <stdio.h>
#include <stdlib.h>

#include "decl.h"

Declaration *createDeclaration(char *name, Type *type, Expression *value, Statement *code) {

	Declaration *node = malloc(sizeof(Declaration));

	node->name = name;
	node->type = type;
	node->value = value;
	node->code = code;
	node->next = NULL;

	return node;

}
