#include <stdio.h>
#include <stdlib.h>

int count;
int i;
int sample;

struct Stack
{
    int top;
    int capacity;
    int* array;
    char name;
    int fakeTop;
};

struct Stack* createStack(char name, int capacity)
{
    struct Stack* stack = malloc(sizeof(struct Stack));
    stack->name = name;
    stack->capacity = capacity;
    stack->top = 0;
    stack->fakeTop = stack->top;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}

void push(struct Stack* stack, int item){
    if (stack->top == stack->capacity)
        return;
    stack->array[++stack->top] = item;
    stack->fakeTop = stack->top;
}

int pop(struct Stack* stack){
    if (stack->top == 0)
        return -1;
    return stack->array[stack->top--];
}

int printPop(struct Stack* stack){
    if (stack->fakeTop == 0)
        return -1;
    return stack->array[stack->fakeTop--];
}

void printState(struct Stack* A, struct Stack* B, struct Stack* C){
	
	while(A->fakeTop != 0)
		printf("%d ", printPop(A));
	printf("      ");
	while(B->fakeTop != 0)
		printf("%d ", printPop(B));
	printf("      ");
	while(C->fakeTop != 0)
		printf("%d ", printPop(C));
	printf("      ");
	A->fakeTop = A->top;
	B->fakeTop = B->top;
	C->fakeTop = C->top;
}

void moveAmountStartEndUsing(int amount, struct Stack* A, struct Stack* B, struct Stack* C){
	
	if(amount == 1){
		count++;
		printf("\n%d Move disc %d from %c to %c", count, amount, A->name, B->name);
	}
	else{
		moveAmountStartEndUsing(amount, A, C, B);
		count++;
		printf("\n%d Move disk %d from %c to %c", count, amount, A->name, B->name);
		moveAmountStartEndUsing(amount, C, B, A);
		}
}

int main(int argc, char *argv[]){

	int inputSize = atoi(argv[1]);

	struct Stack *A = createStack('A', inputSize + 1);
	struct Stack *B = createStack('B', inputSize + 1);
	struct Stack *C = createStack('C', inputSize + 1);

	for(i = inputSize; i > 0; i--){
		push(A, i);
	}
	
	printf("Tower of Hanoi Solver: \n");
	printf("Input number of disks (max 6): %d\n", inputSize);
	printf("Inital State:");
	printState(A, B, C);
	getchar();
	moveAmountStartEndUsing(inputSize, A, B, C);
	
	printf("\n");
	printState(A, B, C);
}