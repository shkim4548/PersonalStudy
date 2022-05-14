import java.util.Scanner;

public class if3 {
    public static void Main(String[] args){
        int a;
        Scanner scanner = new Scanner(System.in);
        a=scanner.nextInt();

        if(a%4==0 && a%100!=0){
            System.out.println(1);
        }
        else if(a%400==0){
            System.out.println(0);
        }
        scanner.close();
    }
}
