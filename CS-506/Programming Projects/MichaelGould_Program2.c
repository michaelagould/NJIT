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
    int title;
    int fakeTop;
};

struct Stack* createStack(int name, int capacity)
{
    struct Stack* stack = malloc(sizeof(struct Stack));
    stack->title = name;
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

void printState(int amount, struct Stack* T1, struct Stack* T2, struct Stack* T3){
	
	while(T1->fakeTop != 0)
		printf("%d ", pop(T1));
	printf("      ");
	while(T2->fakeTop != 0)
		printf("%d ", pop(T2));
	printf("      ");
	while(T3->fakeTop != 0)
		printf("%d ", pop(T3));
	printf("      ");
	T1->fakeTop = T1->top;
	T2->fakeTop = T2->top;
	T3->fakeTop = T3->top;
}

void moveAmountStartEndUsing(int amount, struct Stack* T1, struct Stack* T3, struct Stack* T2){
	
	if(amount == 1){
		count++;
		printf("\n%d (Move disc %d from T%d to T%d):", count, amount, T1->title, T3->title);
		printState(sample, T1, T2, T3);
	}
	else{
		moveAmountStartEndUsing(amount-1, T1, T2, T3);
		count++;
		printf("\n%d (Move disk %d from T%d to T%d):", count, amount, T1->title, T3->title);
		printState(sample, T1, T2, T3);
		moveAmountStartEndUsing(amount-1, T2, T3, T1);
	}
}

int main(int argc, char *argv[]){

	int inputSize = atoi(argv[1]);
	getchar();

	struct Stack *T1 = createStack(1, inputSize);
	struct Stack *T2 = createStack(2, inputSize);
	struct Stack *T3 = createStack(3, inputSize);

	getchar();

	for(i = 0; i <= inputSize; i++){
		push(T1, i);
	}

	printState(inputSize + 1, T1, T2, T3);
	//printf("Tower of Hanoi Solver: \n");
	//printf("Input number of disks (max 6): %d\n", sample);
	//printf("Inital State:");

	getchar();

	moveAmountStartEndUsing(inputSize, T1, T3, T2);
	printf("\n");
}