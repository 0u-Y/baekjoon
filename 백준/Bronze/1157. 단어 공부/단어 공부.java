import java.util.Scanner;
public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        String word = sc.nextLine();

        word = word.toUpperCase();

        int [] count = new int[26];


        int len = word.length();



        for(int i = 0; i<len; i++){
            count[word.charAt(i) - 'A']++;
        }

        int max = -1;
        char ans = 0;



        for(int i=0; i<26; i++){
            if(max < count[i]){
                max = count[i];
                ans = (char)(i + 65);
            }
            else if(max == count[i]){
                ans = '?';
            }
        }


        System.out.print(ans);







    }

}