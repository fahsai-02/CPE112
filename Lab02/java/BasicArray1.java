import java.util.Scanner;

class IntArray{
    private int data[]; //field
    private int size;   //fiekd

    //constructor ชื่อเดียวกับ class
    public IntArray(int capacity){
        data = new int[capacity];
        size = capacity;
    }

    //methods
    public int getSize(){
        return size;
    }

    public boolean setValue(int index, int value){
        if(index < size){
            data[index] = value;
            return true;
        }else{
            return false;
        }
    }

    public int getValue(int index){
        if(index >= size){
            return 999999;
        }else{
            return data[index];
        }
    }

    public boolean insertByIndex(int index, int value){
        if(index >= size){
            return false;
        }else{
            resizeArray();
            for(int i = size; i >= index; i--){
                setValue(i, getValue(i - 1));
            }
            setValue(index, value);
            return true;
        }
    }

    private void resizeArray(){
        int newData[] = new int[getSize()+1];
        for(int i = 0; i < getSize(); i++){
            newData[i] = getValue(i);
        }
        data = newData;
        size++;
    }

}

public class BasicArray1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.printf("Enter array size:");
        IntArray arr = new IntArray(sc.nextInt());


        for(int i = 0; i < arr.getSize() ; i++){
            arr.setValue(i, sc.nextInt());
        }

        int value, index;
        System.out.printf("Enter index:");
        value = sc.nextInt();
        System.out.printf("Enter value:");
        index = sc.nextInt();

        arr.insertByIndex(value, index);


        System.out.println("New array is");
        for(int i = 0; i < arr.getSize() ; i++){
            System.out.printf("%d ", arr.getValue(i));
        }


        sc.close();

        
    }
}
