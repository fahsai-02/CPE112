class Node {
    private int value;
    private Node next;

    public Node(int value){
        this.value = value;
        this.next = null;
    }

    public int getValue(){
        return this.value;
    }
    
    public Node getNext(){
        return this.next;
    }

    public void setValue(int value){
        this.value = value;
    }

    public void setNext(Node next){
        this.next = next;
    }
}


class LinkedList {
    private Node start;

    public LinkedList(){
        this.start = null;
    }

    public void insert(int value){
        Node newNode = new Node(value);
        if(start == null){
            this.start = newNode;
        }else{
            Node currentNode = start;
            while(currentNode.getNext() != null){
                currentNode =currentNode.getNext();
            }
            currentNode.setNext(newNode);
        }
    }

    public void display(){
        if(start == null){
            System.out.println("Empty");
        }else{
            Node currentNode = start;
            while (currentNode != null) {
                System.out.printf("%d ", currentNode.getValue());
                currentNode  =currentNode.getNext();
            }
        }
    }
}

public class LinkList {
    public static void main(String[] args) {
        LinkedList ll = new LinkedList();

        ll.insert(10);
        ll.insert(12);
        ll.insert(50);
        ll.display();
        System.out.println();
        System.out.println("find 10 " + ll.findValue(10));
        System.out.println("find 12 " + ll.findValue(12));
        System.out.println("find 50 " + ll.findValue(50));
        System.out.println("find 0 " + ll.findValue(0));
    }
}
