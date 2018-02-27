#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int COMPCOUNT = 0;

int smaller(int *A, int i, int j){
	if(A[j] < A[j-1])
		COMPCOUNT++;
	return (A[j] < A[j-1]);
}

int main(int argc, char *argv[]){

	int input[atoi(argv[1])];
	int arrayLength = atoi(argv[1]);
	int i, j, temp, init;
	srand(time(NULL));
	
	//WORST INPUT
	//for(init = 0; init <= arrayLength; init++)
	//	input[init] = arrayLength - init;

	//BEST INPUT
	//for(init = 0; init <= arrayLength; init++)
	//	input[init] = init;

	//RANDOM INPUT
	for(init = 0; init <= arrayLength; init++)
		input[init] = rand() % 10 + 1;
	
	printf("Size of sample:%d\n", arrayLength );
	//printf("Array before sorting: ");
	//for(i=0; i < arrayLength; i++)
	//	printf("%d ", input[i]);
	//printf("\n");

	for(i = 1; i < arrayLength; i++){
		j = i;
		while(j > 0 && smaller(input, i, j)){
				temp = input[j];
				input[j] = input[j-1];
				input[j-1] = temp;
		j--;
		}
	}
	//printf("Array after sorting: " );
	//for(i=0; i < arrayLength; i++)
	//	printf("%d ", input[i]);
	//printf("\n");
	printf("Number of swaps:%d\n", COMPCOUNT );
}
