import java.util.Scanner;


public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int sum = 0;
        
        for(int i=0; i<2; i++){
            int a = sc.nextInt();
            sum += a;
        }

        System.out.print(sum);

    }
}