// public class InnerMyQueue {

// }
class Node{
    private int value;
    private Node next;


    public Node(int value){
        this.value = value;
        this.next = null;
    }

    public void setNext(Node next){
        this.next = next;
    }

    public int getvalue(){
        return this.value;
    }

    public Node getNext(){
        return this.next;
    }
    

}

class Queue{
    private Node front;
    private Node rear;

    public Queue(){
        this.front = null;
        this.rear = null;
    }

    public void Enqueue(int value){
        Node newNode = new Node(value);
        if(isEmpty()){
            this.front = newNode;
            this.rear = newNode;
        }else{
            this.rear.setNext(newNode);
            this.rear = newNode;
        }
    }

    public int Dequeue(){
        if(!isEmpty()){
            int value = this.front.getvalue();
            if(this.front == this.rear){
                this.rear = null;
                this.rear = null;
            }
            this.front = this.front.getNext();
            return value;
        }else{
            return -1;
        }
    }

    private boolean isEmpty(){
        return this.front == null;
    }
}

public class MyQueue {
    public static void main(String[] args) {
        Queue q = new Queue();
        q.Enqueue(10);
        q.Enqueue(20);
        q.Enqueue(30);
        q.Enqueue(40);
        q.Enqueue(50);
        System.out.println(q.Dequeue());
        System.out.println(q.Dequeue());
        System.out.println(q.Dequeue());
        System.out.println(q.Dequeue());
        System.out.println(q.Dequeue());
        System.out.println(q.Dequeue());

        
    }
}
