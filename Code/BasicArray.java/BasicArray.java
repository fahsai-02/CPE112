import java.util.Scanner;

class IntArray{
    private int []data;
    private int size;

    public IntArray(int capacity){
        data = new int[capacity];
        size = capacity;
    }

    public int getSize(){
        return size;
    }

    public boolean setValue(int index, int value){
        if(index >= size){
            return false;
        }else{
            data[index] = value;
            return true;
        }
    }

    public int getValue(int index){
        return data [index];
    }
    // arr.getValue[0]

    public void resize(){
        int []newData = new int[size + 1];
        for (int i = 0; i < size; i++){
            newData[i] = data[i];
        }
        size++;
        // newData[size] = -1;
        data = newData;
    }

    public void insertElement(int index, int value){
        resize(); // size++, data[size++]
        for(int i = size-1; i > index; i--){
            data[i] = data[i-1];
            // [][]     [][]
        }
        // [][](value)[][]
        data[index] = value;
    }
}


public class BasicArray{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        // System.out.print("Enter Size : ");
        // int []arr = new int[100]; //new is constructure คือ กำหนดรูปร่าง

        IntArray wai = new IntArray(5);
        System.out.print("Enter Data : ");
        
        for (int i = 0; i < wai.getSize(); i++){
            wai.setValue(i, sc.nextInt());
        }
        
     
        System.out.print("Enter Index and value : ");
        System.out.println();
        wai.insertElement(sc.nextInt(), sc.nextInt());
        for (int i = 0; i < wai.getSize(); i++){
            System.out.printf("%d ",wai.getValue(i));
        }
        sc.close();
    }
}