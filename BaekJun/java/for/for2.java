import java.util.Scanner;

public class for2 {
    public static void main(String[] args){
        int n, m, a;
        Scanner scanner = new Scanner(System.in);

        n=scanner.nextInt();
        for(int i=0;i<n;i++){
            m=scanner.nextInt();
            a=scanner.nextInt();
            System.out.println(m+a);
        }
        scanner.close();
    }
}
