#include <stdio.h>

int fact(int n){
	if (n == 1){
		printf("there %d \n", n);
		return n;
	}
	else{
		printf("Here %d \n", n);
		n = n * fact(n-1);
		//printf("Here 2 %d \n", n);
	}
}

int main(){
	printf("%d \n", fact(5));
}