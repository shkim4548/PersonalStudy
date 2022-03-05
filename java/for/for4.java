import java.util.Scanner;

public class for4{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int n,a,b;
        n= scanner.nextInt();
        for(int i=0;i<n;i++){
            a=scanner.nextInt();
            b=scanner.nextInt();
            System.out.println(a+b);
        }
        scanner.close();
    }
}