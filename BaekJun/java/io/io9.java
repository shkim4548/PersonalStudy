import java.util.Scanner;

public class io9 {
    public static void main(String[] args){
        int a,b,sum,sub,mul,mod;
        double div;
        Scanner scanner = new Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();
        sum=a+b;
        sub=a-b;
        mul=a*b;
        div=(double)a/(double)b;
        mod=a%b;
        System.out.printf("%d\n%d\n%d\n%f\n%d",sum,sub,mul,div,mod);

        scanner.close();
    }
}
