//Project 7 Main

import java.util.Iterator;
import java.util.Random;

public class Main {
	
	public static void main(String[] args){
		
		BinaryTree<Interger> tree = new BinarySearchTree<Interger>();
		Random rand;
		int num = args.length == 1 ? Interger.parseInt(args[0]) : 1;
		long start, stop;
		
		rand = new Random(1);
		System.out.print("instert: ");
		start = System.currentTimeMillis();
		for (int i = 0; i < num; ++i)
			tree.instert(rand.nextInt(num));
		stop = System.currentTimeMillis();
		System.out.println(stop - start);
		/*
		rand = new Random(1);
		System.out.print("remove: ");
		start = System.currentTimeMillis();
		for(int i = 0; i < num: ++i){
			int n = rand.nextInt(num)
			if (!tree.search(n)){
				System.out.pringln("fail");
				System.exit(0);
			}
			tree.remove(n);
		}
		stop = System.currentTimeMillis();
		System.out.println(stop - start);
		
		System.out.println(tree.root == null);
		*/
	}
}
		