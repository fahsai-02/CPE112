// import java.util.Scanner;

class Node {
    private int data;
    private Node next;
   
    public Node (int data){
        this.data = data;
        this.next = null;
    }
    public Node (Node next){
        this.next = next;
    }

    public int getData(){
        return this.data;
    }

    public Node getNext(){
        return this.next;
    }

    // public void setData(int data){
    //     this.data = data;
    // }

    public void setNext(Node next){
        this.next = next;
    }

}

class LinkList{
    private Node start;

    public LinkList(){
        this.start = null;
    }

    public void insert(int data){
        Node newNode = new Node(data);
        if(start == null){
            this.start = newNode;
        }else{
            Node currentNode = start;
            while (currentNode.getNext() != null) {
                currentNode = currentNode.getNext();
            }
            currentNode.setNext(newNode);
        }
    }

    public void delete(){
        Node ptr = new Node(start);
        if(start == null){
            System.out.println("Out of stack");
        }else{
            while (ptr.getNext() != null) {
                ptr.setNext(ptr.getNext());
            }

        }
    }
}

public class FullstackLinkedList {
    public static void main(String[] args){
        // Scanner sc = new Scanner(System.in);
        // int n = sc.nextInt();
    }
}