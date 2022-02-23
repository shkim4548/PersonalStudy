import java.util.Scanner;

public class io12 {
    public static void main(String[] args){
        int A,B,C;
        Scanner scanner = new Scanner(System.in);
        A=scanner.nextInt();
        B=scanner.nextInt();
        C=scanner.nextInt();

        System.out.printf("%d\n%d\n%d\n%d",(A+B)%C, ((A%C) + (B%C))%C,(A*B)%C,((A%C)*(B%C))%C);
        scanner.close();
    }
}
