#ifndef __UTIL_H
#define __UTIL_H

#include "statement.h"

extern char *scanned_text;
extern char *append_scan(char *in);
extern void append_statement(Statement *stmt);
extern Statement *get_statements();

// removes all statements from the linked list
extern void reset_statements();
// remove a single statement from the linked list
extern void remove_statement(Statement *stmt);
// remove all statements (inclusive) from the provided statement.
extern void remove_statements(Statement *stmt);

#endif // __UTIL_H
