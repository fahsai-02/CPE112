class Node{
    int data;
    Node left;
    Node right;

    public Node(int data){
        this.data = data;
        this.right = null;
        this.left = null;
    }

    // public boolean setChildNode(Node child, char direction){

    // }
}

public class refType {
    public static void main(String[] args) {
        Node n1 = new Node(50);
        Node n2 = new Node(53);
        
        System.out.println(n1 == n2);

        n2=n1;
        n1.data = 80;
        System.out.println(n2.data);
    }
}
