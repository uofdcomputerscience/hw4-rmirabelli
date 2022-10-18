#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct t_node {
	int data;
	struct t_node *next;
} Node;

Node *newNode(int data) {
	Node *nn = malloc(sizeof(Node));
	nn->data = data;
	nn->next = NULL;
	return nn;
}

int main(int argc, char **argv) {

	// accept size from command line!
	
	if (argc != 2) return -1;
	int size = atoi(argv[1]);

	Node *head = NULL;
	head =  newNode(0);
	Node *insert = head;

	// build list
	for (int i = 1; i <= size; ++i) {
		insert ->next = newNode(i);
		insert = insert->next;
	}

	// print data
	Node *walk = head;
	while (walk->next != NULL) {
		printf("%d ", walk->data);
		walk = walk->next;
	}

	printf("\n");

	// clean up after ourselves
	Node *toFree = head;
	while (toFree) {
		Node *next = toFree->next;
		free(toFree);
		toFree = next;
	}

	return 0;

}
