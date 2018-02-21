#include <stdio.h>
#include <stdlib.h>

/*
Michael Gould
CS 288 2018S Section 006
HW 02
*/

/* self-referential structure */
struct Node {
	int id;
	int grade;
	struct Node *next;
};

struct List {
	struct Node *head;
	struct Node *tail;
};


struct List SLL_new(){
	/* construct an empty list */
	struct List list;
	list.head = NULL;
	list.tail = NULL;
	return list;
}

int SLL_length(struct List *list) {
	/* return the number of items in the list */
	struct Node *p;

	int n = 0;
	for (p = list->head; p != NULL; p = p->next) {
		++n;
	}
	return n;
}

int SLL_empty(struct List *list) {
	/* return true if the list contains no items */
	return list->head == NULL;
}

struct Node * SLL_pop(struct List *list) {
	/* remove and return the first item of the list */
	struct Node *node = list->head;
	list->head = node->next;
	if (SLL_empty(list)) {
		list->tail = NULL;
	}
	struct Node *product = node;
	free(node);
	return product;
}

void SLL_clear(struct List *list) {
	/* remove all the items from the list */
	while (!SLL_empty(list)) {
		SLL_pop(list);
	}
}

void SLL_push(struct List *list, struct Node *inputNode) {
	/*  insert the item at the front of the list */
	struct Node *node = malloc(sizeof(struct Node));
	node->id = inputNode->id;
	node->grade = inputNode->grade;
	node->next = list->head;
	if (SLL_empty(list)) {
		list->tail = node;
	}
	list->head = node;
}

void SLL_append(struct List *list, struct Node *inputNode) {
	/* append the item to the end of the list */
	if (SLL_empty(list)) {
		SLL_push(list, inputNode);
	}
	else {
		struct Node *node = malloc(sizeof(struct Node));
		node->id = inputNode->id;
		node->grade = inputNode->grade;
		node->next = NULL;
		list->tail->next = node;
		list->tail = node;
	}
}

void insert(struct List *list, struct Node *inputNode){

	struct Node *test = list->head;
	struct Node *prev = test;

	if (SLL_empty(list)) {
		list->head = inputNode;
		list->tail = inputNode;
		return;
	}

	if(list->tail->id <= inputNode->id) {
		SLL_append(list,inputNode);
		return;
	}

	if (test->next == NULL || test->id >= inputNode->id) {
		SLL_push(list, inputNode);
		return;
	}
	if(test->next == NULL && test->id < inputNode->id) {
		SLL_append(list, inputNode);
		return;
	}
	
	while(inputNode->id > test->id){
		prev = test;
		test = test->next;
	}

	inputNode->next = test;
	prev->next = inputNode;
}

int main(int argc, char *argv[]) {
	
	int id, grade, i, avg;
	FILE *ifp, *ofp = NULL;
	struct List list = SLL_new();

	for (i = 1; i < (argc-1); ++i) {
		ifp = fopen(argv[i], "r");
		while (fscanf(ifp, "%d,%d", &id, &grade) == 2) {
			struct Node *input = malloc(sizeof(struct Node));
			input->id = id;
			input->grade = grade;
			input->next = NULL;
			insert(&list, input);
			}
		fclose(ifp);
	}
	
	//struct Node *tmp = list.head;
	ofp = fopen(argv[argc-1], "w");
	while (list.head != NULL) {
		struct Node *temp = SLL_pop(&list);
		id = temp->id;
		avg = (int)(((temp->grade + SLL_pop(&list)->grade + SLL_pop(&list)->grade)/3) + 0.5);
		fprintf(ofp, "%d, %d\n", id, avg);
	}
	fclose(ofp);
	
return 0;
}