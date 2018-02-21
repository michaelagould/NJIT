#include <stdio.h>
#include <stdlib.h>

int input[] = {2,1,6,5,3};
int COMPCOUNT = 0;

int SMALLER(int *input, int i, int j){
	
	if(input[i] < input[j] && j >= 0){
		input[j+1] = input[j];
		j--;
		COMPCOUNT++;
		return 1;
	}
	else
		return 0;
}

int main(){

	int j;
	int i = 1;
	while(i < ((sizeof(input)/sizeof(input[0]) - 1))){
		j = i - 1;
		while(SMALLER(input[],i,j){
			;
		}
	}
	input[j+1] = input[i];
	i++;
}