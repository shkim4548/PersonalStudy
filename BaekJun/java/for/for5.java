import java.util.Scanner;

class Main{
    public static void main(String[] args){
        int n;
        Scanner scanner = new Scanner(System.in);
        n=scanner.nextInt();
        for(int i=1;i<=n;i++){
            System.out.println(i);
        }
        scanner.close();
    }
}