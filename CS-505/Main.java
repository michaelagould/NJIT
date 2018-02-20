//Project 7 Main

import java.util.Iterator;
import java.util.Random;

public class Main {
	
	public static void main(String[] args){
		
		BinaryTree<Integer> tree = new BinarySearchTree<Integer>();
		Random rand;
		int num = args.length == 1 ? Integer.parseInt(args[0]) : 10;
		long start, stop;
		
		rand = new Random(1);
		System.out.print("insert: ");
		start = System.currentTimeMillis();
		for (int i = 0; i < num; ++i)
			tree.insert(rand.nextInt(num));
		stop = System.currentTimeMillis();
		System.out.println(stop - start);
		rand = new Random(1);
		System.out.print("remove: ");
		start = System.currentTimeMillis();
		for(int i = 0; i < num; ++i){
			int n = rand.nextInt(num);
			if (!tree.search(n)){
				System.out.println("fail");
				System.exit(0);
			}
		}
		stop = System.currentTimeMillis();
		System.out.println(stop - start);
		
		System.out.println(tree.root == null);
		
	}
	
}
		