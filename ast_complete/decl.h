#ifndef __DECL_H
#define __DECL_H

#include "expr.h"
#include "type.h"
#include "stmt.h"

typedef struct t_decl {

	const char			*name;
	Type				*type;
	Expression			*value;
	struct t_statement	*code;
	struct t_decl		*next;

} Declaration;

extern Declaration *createDeclaration(char *name, Type *type, Expression *value, struct t_statement *code);

#endif // __DECL_H
