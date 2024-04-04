import java.util.Scanner;
public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        String num;

        char c;

        int cnt = 0;

        for(int i=1; i<=n; i++){
            num = Integer.toString(i);
            for(int j=0; j<num.length(); j++){
                c = num.charAt(j);
                if(c == '3' || c == '6' || c =='9'){
                    cnt++;
                }
            }
        }

        System.out.print(cnt);


    }

}