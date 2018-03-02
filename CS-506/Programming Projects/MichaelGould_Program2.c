#include <stdio.h>
#include <stdlib.h>

int count;

void moveAmountStartEndUsing(int n, char A, char B, char C){
	
	if(n == 1){
		count++;
		printf("\n%d Move disc %d from %c to %c", count, n, A, B);
	}
	else{
		moveAmountStartEndUsing(n-1, A, C, B);
		count++;
		printf("\n%d Move disk %d from %c to %c", count, n, A, B);
		moveAmountStartEndUsing(n-1, C, B, A);
		}
}

int main(int argc, char *argv[]){

	int n = atoi(argv[1]);

	if(n > 6){
		printf("Input too large, quitting program\n");
		return 0;
	}

	else{
	printf("Tower of Hanoi Solver: \n");
	printf("Input number of disks (max 6): %d", n);
	moveAmountStartEndUsing(n, 'A', 'B', 'C');
	printf("\n");
	}
}