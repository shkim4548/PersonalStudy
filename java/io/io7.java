import java.util.Scanner;

public class io7 {
    public static void main(String[] args){
        int a,b,res;
        Scanner scanner = new Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();
        res=a*b;
        System.out.println(res);

        scanner.close();
    }
}
