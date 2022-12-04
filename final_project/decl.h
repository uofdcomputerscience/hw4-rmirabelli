#ifndef __DECL_H
#define __DECL_H

#include "expr.h"
#include "type.h"
#include "statement.h"

typedef struct t_decl {

	const char         *name;
	Type               *type;
	Expression         *value;
	struct t_statement *code;
	struct t_ast_node  *next;

} Declaration;

//extern Declaration *createDeclaration(const char *name, Type *type, Expression *value, struct t_statement *code);


#endif // __DECL_H
