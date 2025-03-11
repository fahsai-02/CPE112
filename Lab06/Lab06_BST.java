// Nakagamon Saengdara 67070501064

import java.util.Scanner;

class Node{
    int value;
    Node left;
    Node right;

    public Node(int value){
        this.value = value;
        this.right = null;
        this.left = null;
    }

    // public boolean setChildNode
}

class Tree{
    Node root;

    public Tree(){
        this.root = null;
    }
    
    public void insert(int value ){
        Node newNode = new Node(value);
        if(this.root == null){
            this.root = newNode;
            return;
        }
        
        Node currNode = this.root;
        while (true) {
            if(newNode.value < currNode.value){
                if(currNode.left == null){
                    currNode.left = newNode;
                    return;
                }
                currNode = currNode.left;
            }
            else if(newNode.value > currNode.value){
                if(currNode.right == null){
                    currNode.right = newNode;
                    return;
                }
                currNode = currNode.right;
            }
        }
    }
    private void inorder(Node root) {
        if (root != null) {
            inorder(root.left);
            System.out.print(root.value + " ");
            inorder(root.right);
        }
    }

    public void inorder() {
        inorder(this.root);
        System.out.println();
    }

    
}

public class Lab06_BST {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = 0;
        Tree tree = new Tree();

        while(true){
            n = sc.nextInt();
            if(n == -1){
                break;
            }
            tree.insert(n);
        }
        sc.close();

        tree.inorder();
    }
}
