#include <stdio.h>
#include <stdlib.h>

int COMPCOUNT = 0;

int smaller(int *A, int j, int i){
	if(A[j] < A[j-1])
		COMPCOUNT++;
	return (A[j] < A[j-1]);
}

int main(int argc, int *argv[]){

	//int n = (int)strtol(argv[1])
	//int input[argv[1]];
	int i, j, temp, init;
	int arrayLength = (sizeof(input)/sizeof(input[0]));
	//int seed = time(NULL);
	//srand(seed);
	//for(init = 0; init <= argv[1]; init++)
	//	input[init] = rand();

	
	for(i = 1; i < arrayLength; i++){
		j = i;
		while(j > 0 && smaller(input, j, i)){
				temp = input[j];
				input[j] = input[j-1];
				input[j-1] = temp;
		}
	}
	printf("%d\n", COMPCOUNT );
	for(i=0; i < arrayLength; i++)
		printf("%d ", input[i]);
}
