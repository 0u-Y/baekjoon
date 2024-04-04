
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();

        num = 1000 - num;

        int cnt = 0;

        cnt += (num/500); num%=500;
        cnt += (num/100); num%=100;
        cnt += (num/50); num%=50;
        cnt += (num/10); num%=10;
        cnt += (num/5); num%=5;
        cnt += num;


        System.out.print(cnt);


    }
}

