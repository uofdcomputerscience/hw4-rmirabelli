#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"

// appends the provided string to a table of strings, and then returns a pointer to
// the newly allocated string.
//
// This could be improved with pooling.

char *scanned_text;

typedef struct t_str_node {
	char *string;
	struct t_str_node *next;
} StrNode;

char *append_scan(char *in) {
	static StrNode head;
	static StrNode *current = &head;
	current->next = malloc(sizeof(StrNode));
	current = current->next;
	current->string = malloc(strlen(in) + 1);
	strcpy(current->string, in);
	scanned_text = current->string;
	return current->string;
}

Statement *head = NULL;
// append statement to the linked list of statements
void append_statement(Statement *stmt) {
	if (head == NULL) { head = stmt; return; }
	Statement *cur = head;
	while (cur->next) { cur = cur->next; }
	cur->next = stmt;
}

Statement *get_statements() { return head; }
