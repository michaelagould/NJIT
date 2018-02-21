import java.lang.Math;

//Michael Gould
//CS 505-851
//314-52-087

public class Main {
	
	public static void main(String[] args){
		
		int[] array = new int[Integer.parseInt(args[0])];
		for(int i = 0; i < array.length; i++) {
			array[i] = i + 1;
		}
		sieve(array);
		goldbach(array);	
	}
	
	public static void sieve(int[] array){
		
		int upperBound = (int)(Math.sqrt(array.length));		
		
		for(int i = 1; i < upperBound; i++){
			if(array[i] != 0) {
				for(int j = (array[i] * 2 - 1); j < array.length; j += array[i]) {
					array[j] = 0;
				}
			}
		}
		
		for(int i = 0; i < array.length; i++)
			System.out.println(array[i]);
	}
	
	public static void goldbach(int[] array){
		
		int count = 0;
		int[] evens = new int[(array.length / 2) - 1];
		
		//initializes array of evens 
		for(int i = 4; i <= array.length; i = i + 2){
			evens[count] = i;
			count++;
		}
	
		count = 0;
		
		//initializes array of primes w/ no zeros
		for(int i = 0; i < array.length; i++){
			if(array[i] != 0)
				count++;
		}
		
		int[] primes = new int[count];
		count = 0;
				
		for(int i = 0; i<array.length; i++){
			if (array[i] != 0) {
			primes[count] = array[i];
			count++;
			}
		}
				
		//outputs two primes who's sum equals even
		for(int i = 0; i < evens.length; i++){
			int small = 0;
			int large = count - 1;
			while (small < large){
				if (primes[small] + primes[large] == evens[i])
					break;
				else if (primes[small] + primes[large] < evens[i])
				small++;
				else
				large--;
			}
			if (primes[small] + primes[large] == evens[i])
				System.out.println(primes[small] + " + " + primes[large] + " = " + evens[i]);
			else
				System.out.println("There is no to primes who's sum is " + evens[i]);
			}
	}		
}