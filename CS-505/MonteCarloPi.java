import java.util.Scanner;
import java.lang.Math;

//Michael Gould
//CS 505-851
//314-52-087

public class MonteCarloPi{

public static void main(String[] args) {

	System.out.print("Please enter number of iterations: ");
	Scanner scan = new Scanner(System.in);
	int sampleSize = scan.nextInt();
	System.out.print((generateRatio(sampleSize)/sampleSize) * 4);
	scan.close();
}

public static double generateRatio(int sampleSize){
	
	int count = 0;
	double x;
	double y;
	int numInside = 0;
	
	while(count < sampleSize){
		x = Math.random();
		y = Math.random();
		if(x * x + y * y <= 1) ++numInside;
		++count;
	}
	return numInside;
}	
}