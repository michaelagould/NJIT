#include <stdlib.h>
#include <string.h>

int main(){

	int move;
	char field[71];
	
	//initializes field with all blank slots represented by 70 underscores
	for(int i = 0; i < (char)(sizeof(field) / sizeof(field[0]); i++)
		field[i] = '_';
		
	//begins loop for movement
	printf("BANG!!!!!\n AND THEY'RE OFF!!!!!\n");
	while((harePosition <= 71) && (tortoisePosition <= 71)){
		harePosition = ((harePosition + (move = moveHare())) > 1) ? (harePosition += move) : 1;
		tortPosition = ((tortPosition + (move = moveTortoise())) > 1) ? (tortoisePosition += move) : 1;
		
		//takes results from race and determines winner or tie
		if((harePosition >= 71) && (tortoisePosition >= 71)
			printf("IT'S A TIE");
		else if(harePosition >= 71 || tortoisePosition >= 71)
			printf((tortoisePosition > harePosition) ? "TORTOISE WINS!!! YAY!!!" : "HARE WINS. YUCH.");	
		else
		printCurrentPosition(tortoisePosition, harePosition);
		printf("\n");
	}	
}

int moveTortoise(){
		
	int rollDice = ((rand() % 10) + 1);
	if(1 <= rollDice <= 5)//fast plod
		return 3;
	else if(6 <= rollDice <= 7)//slip
		return -6;
	else //slow plod
		return 1;
}
int moveHare(){
	
	int rollDice = ((rand() % 10) + 1);
	if(1 <= rollDice <= 2)//sleep
		return 0;
	else if(3 <= rollDice <= 4)//big hop
		return 9;
	else if(5 == rollDice)//big slip
		return -12;
	else if(6 <= rollDice <= 8)//small hop
		return 1;
	else//small slip
		return -2;
}
void printCurrentPosition(int tortoisePosition, int harePosition){
	
	if(tortoisePosition != harePosition){
		field[tortoisePosition] = 'T';
		field[harePosition] = 'H';
	}
	else
		field[harePosition] = 'O'; //temp escape char for special case
	
	for(int i = 0; i < 71; i++){
		if(getchar(field[i]) == 'O')
			printf("Ouch!!!");
		else
			printf("%c",getchar(field[i]));	
}