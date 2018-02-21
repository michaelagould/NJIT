#include <stdio.h>
#include <stdlib.h>

int main(int argc char *argv[]){

	input = toInt(argv[1]);
	bitcount(1,input);
}

int decToBin(int input){


	
}

int bitSize(int count, int input){

	if(input <= count)
		return count;
	else{
		bitSize(count++,input - 2)
	}
}