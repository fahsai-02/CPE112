// import java.util.Scanner;

class Node {
    public String name;
    public int val;
    public Node left;
    public Node right;

    public Node(int n){
        this.val = n;
        this.left = null;
        this.right = null;
    }

    public boolean setChildNode(Node child, char direction){
        if(direction == 'R'){
            this.right = child;
            return true;
        }else if (direction == 'L'){
            this.left = child;
            return true;
        }
        return false;
    }
}

class Tree {
    Node []node;
    Node root ;
    int size;

    public Tree(int n){
        this.node = new Node[n];
        this.root = null;
    }

    private Node searchName(String name){
        for (Node n : this.node ){
            if(n != null)

        }
    }

}




public class lab05_byMyself {
    
}
