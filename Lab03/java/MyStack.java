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

class Stack{
    private Node top;

    public Stack(){
        this.top = null;
    }

    public void push(int value){
        Node newNode = new Node(value);
        if(isEmpty()){
            this.top = newNode;
        }else{
            newNode.setNext(top);
            this.top = newNode;
        }
    }

    public int pop(){
        if(isEmpty()){
            System.out.println("Empty");
            return -1;
        }else{
            int val = top.getvalue();
            top = top.getNext();
            return val;
        }
    }

    public int top(){
        if(isEmpty()){
            System.out.println("Empty");
            return -1;
        }else{
            return top.getvalue();
        }
    }

    public boolean isEmpty(){
        return this.top == null ? true : false;
    }
}


public class MyStack{
    public static void main(String[] args) {
        Stack st = new Stack();
        st.push(0);
        st.push(1);
        st.push(2);
        st.push(3);
        System.out.println(st.pop());
        System.out.println(st.pop());
        System.out.println(st.pop());
        System.out.println(st.pop());
        System.out.println(st.pop());
    }
}