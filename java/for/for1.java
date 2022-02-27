import java.util.Scanner;

public class for1 {
    public static void main(String[] args){
        int a;
        int res;
        Scanner scanner = new Scanner(System.in);

        a=scanner.nextInt();
        for(int i=1;i<=9;i++){
            res=a*i;
            System.out.println(a+"*"+i+"="+res);
        }
        scanner.close();
    }
}
