import java.util.Scanner;   //scan

/*print */
public class HelloWorld{
    static void myName(String name){   //void myName(char *name)
        System.out.print(name + "\n");
    }


    public static void main(String[] args){
        System.out.printf("Hello World 2\n");
        System.out.print("Hello World 1\n");
        System.out.println("Hello World 3");    //new line

        Scanner sc/* ชื่อ scanner ตั้งเป็นอะไรก็ได้*/ = new Scanner(System.in);
        // int x = sc.nextInt();   //scanf("%d", &x);
        // int n = 5;

        // for (int i = 0; i <= n; i++){
        //     myName(sc.nextLine());
        // }
        // String name = sc.nextLine();
        // myName(name);
        // System.out.print(name);

        // int n = Integer.parseInt(sc.nextLine());
        /*
         * 5\n > int > 5
         * 
         * ถ้าไม่แปลง
         * 5
         * \n
         * 
         */

        // for (int i = 0; i < n; i++){
        //     myName(sc.nextLine());
        // }


        /*array in java*/
        int []arr = {1,2,3,4,5};
        int arr2[] = new int[5];    //int *arr2 = (int *)calloc(sizeof(int)*5);

        int n = Integer.parseInt(sc.nextLine());
        String stds[] = new String[n];
        int i=0;
        while(i<n){     //while(n--) ไม่ต้องประกาศ i
            stds[i] = sc.nextLine();
            i = i+1;
        }

        for(String x : stds){
            myName(x);
        }

        sc.close(); //close scanner
    }   
}