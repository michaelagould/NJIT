public abstract class BinaryTree<E> implements Tree<E> {

    protected class Node<T> {
        protected Node(T data) {
            this.data = data;
        }
        protected T data;
        protected Node<T> left;
        protected Node<T> right;
    }

    protected Node<E> root;
    
    public Node<E> getRoot(){return root;}
    
    public void traverse(Node<E> curr) {
        if (curr != null) {
            traverse(curr.left);
            System.out.print(curr.data + " ");
            traverse(curr.right);
        }
    }
}