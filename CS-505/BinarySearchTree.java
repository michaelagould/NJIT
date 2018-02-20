import java.util.Iterator;
import java.util.Stack;

public class BinarySearchTree<E extends Comparable<? super E>> extends BinaryTree<E> {
	
	public int size = 0; 
	
	public Iterator<E> iterator(){
		return new Iterator<E>(){
			
			private Stack<Node> stack = new Stack<>();
		    private Node<E> curr = root;
			
		    public E next() {
		        while (curr != null) {
		            stack.push(curr);
		            curr = curr.left;
		        }

		        curr = stack.pop();
		        Node<E> node = curr;
		        curr = curr.right;

		        return (E) node;
		    }

		    public boolean hasNext() {
		        return (!stack.isEmpty() || curr != null);
		    }
			
			public void remove() {
			throw new UnsupportedOperationException();
			}	
		};
	}
	
	public void insert(E data) {
		Node<E> temp = new Node<E>(data);
		root = insert(root, temp);
		size++;
	}
	
	private Node<E> insert(Node<E> curr, Node<E> node) {
		
		if(curr == null)
			return node;
		else if(curr.data.compareTo(node.data) <= 0)
			curr.right = insert(curr.right, node);
		else
			curr.left = insert(curr.left, node);
		return curr;
	}
	
	public boolean empty() {
		return root == null;
	}
	
    public void remove(E key) {
        root = remove(root, key);
    }
    
	private Node<E> remove(Node<E> curr, E key){
		
		if(curr == null)
			return curr;
		
		if (curr.data.compareTo(key) > 0)
            curr.left = remove(curr.left, key);
        else if (curr.data.compareTo(key) < 0)
            curr.right = remove(curr.right, key);
        else{
        	
        	if (curr.left == null)
        		return curr.right;
        	else if (curr.right == null)
        		return curr.left;	
        	curr.data = findIOP(curr).data;
        	curr.left = remove(curr.left, curr.data);
        }
        return curr;
	}

	private Node<E> findIOP(Node<E> node) {
		Node<E> curr;
		for (curr = node.left; curr.right != null; curr = curr.right);
		return curr;
	}
	/*
	private Node<E> smallest(Node<E> curr)
    {
        Node<E> smallest = curr.data;
        while (curr.left != null)
        {
            smallest = curr.left.data;
            curr = curr.left;
        }
        return smallest;
    }
	*/
  	public boolean search(E key) {
		return search(root, key);
	}
	
	private boolean search(Node<E> curr, E key) {
		
		if(curr == null)
			return false;
		else if (key.compareTo(curr.data) == 0) 
			return true;
		else if (key.compareTo(curr.data) < 0)
			return search(curr.left, key);
		else
			return search(curr.right, key);   
    }	
}