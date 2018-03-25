#include <stdio.h>
#include <stdlib.h>

int main(){

	length(Struct List *list){

		Struct Node *p;
		int length = 0;
		for(p = list->head; p != NULL; p = p->next,length++)
		return length;
	}

	compare(Struct List *list, int key){

		Struct Node *p = list->head;
		while(p != NULL){
			p->data = (key > list->data) ? 0 : p->data;
			p = p->next;
		}
	}
}