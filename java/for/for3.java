import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        int n;
        int res=0;
        Scanner scanner = new Scanner(System.in);

        n = scanner.nextInt();
        for(int i=1; i<=n; i++){
            res+=i;
        }
        System.out.println(res);
        scanner.close();
    }
}
