import java.util.Scanner;

public class io6 {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();

        int res = a-b;

        System.out.println(res);

        scanner.close();
    }
}
