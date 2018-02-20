#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

char field[71];

int moveTortoise(){
	
	int rollDice = ((rand() % 10) + 1);
	if(1 <= rollDice && rollDice <= 5)//fast plod
		return 3;
	else if(6 <= rollDice && rollDice <= 7)//slip
		return -6;
	else //slow plod
		return 1;
}

int moveHare(){
	
	int rollDice = ((rand() % 10) + 1);
	if(1 <= rollDice && rollDice <= 2)//sleep{
		return 0;
	else if(3 <= rollDice && rollDice <= 4)//big hop
		return 9;
	else if(5 == rollDice)//big slip
		return -12;
	else if(6 <= rollDice && rollDice <= 8)//small hop
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
		if(field[i] == 'O') {
			printf("Ouch!!!");
			i += 6;
		}
		else
			printf("%c",field[i]);
	}
	
	field[tortoisePosition] = '_';
	field[harePosition] = '_';
}

int main(){

	int move;
	int tortPosition, harePosition;
	
	srand(time(NULL));
	
	//initializes field with all blank slots represented by 70 underscores
	for(int i = 0; (i < (char)sizeof(field) / sizeof(field[0])); i++)
		field[i] = '_';
		
	//begins loop for movement
	printf("BANG!!!!!\n AND THEY'RE OFF!!!!!\n");
	while((harePosition <= 71) && (tortPosition <= 71)){
		
		harePosition = (harePosition + (move = moveHare()) > 1) ? (harePosition += move) : 1;
		tortPosition = (tortPosition + (move = moveTortoise()) > 1) ? (tortPosition += move) : 1;
		
		//takes results from race and determines winner or tie
		if((harePosition >= 71) && (tortPosition >= 71))
			printf("IT'S A TIE");
		else if(harePosition >= 71 || tortPosition >= 71)
			printf((tortPosition > harePosition) ? "TORTOISE WINS!!! YAY!!!" : "HARE WINS. YUCH.");	
		else
		printCurrentPosition(tortPosition, harePosition);
		printf("\n");
	}

	return 0;	
}