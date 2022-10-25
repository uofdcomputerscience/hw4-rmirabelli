#include <stdio.h>
#include <stdlib.h>

typedef struct t_node {
	int value;
	struct t_node *next;
} Node;

Node *reverse(Node *head) {
	Node *prev = NULL;
	Node *cur = head;
	Node *next = NULL;

	while (cur) {
		next = cur->next;
		cur-> next = prev;
		prev = cur;
		cur = next;
	}
	
	return prev;
}

int main(int argc, char **argv) {

	if (argc != 2) return -1;

	int count = atoi(argv[1]);

	Node *head = NULL;
	Node *cur = NULL;

	for (int i = 0; i < count; ++i) {
		Node *next = malloc(sizeof(Node));
		next->value = i;
		next->next = NULL;
		if (cur != NULL) {
			cur->next = next;
		}
		if (head == NULL) {
			head = next;
		}
		cur = next;
	}

	cur = head;
	Node *mid = cur;

	while (cur) {
		cur = cur->next;
		if (cur) cur = cur->next;
		mid = mid->next;
	}
	printf("midpoint is %d\n", mid->value);
}

