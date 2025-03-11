import java.util.Scanner;
class TwoDArr{
    public static void main(String[] args){
        // int[] arr = new int[10];
        Scanner sc = new Scanner(System.in);
        int[][] matrix1 = new int[3][3];
        int[][] matrix2 = new int[3][3];
        int[][] matrix3 = new int[3][3];

        for(int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                matrix1[i][j] = sc.nextInt();
            }
        }
        for(int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                matrix2[i][j] = sc.nextInt();
            }
        }
        for(int[] row : matrix3){
            for (int ele : row){
                System.out.printf("%d ", ele);
            }
            System.out.println("\n");
        }
        sc.close();
    }
}