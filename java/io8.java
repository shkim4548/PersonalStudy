import java.util.Scanner;

public class io8 {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        double a = scanner.nextDouble();
        double b = scanner.nextDouble();
        double res = a/b;
        
        System.out.println(res);
        scanner.close();
    }
}
