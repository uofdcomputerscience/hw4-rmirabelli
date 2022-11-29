#ifndef __UTIL_H
#define __UTIL_H

#include "statement.h"

extern char *scanned_text;
extern char *append_scan(char *in);
extern void append_statement(Statement *stmt);
extern Statement *get_statements();

#endif // __UTIL_H
