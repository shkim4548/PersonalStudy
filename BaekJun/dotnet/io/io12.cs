using System;

class io12{
    static void Main(String[] args){
        int a,b,c;
        a=int.Parse(Console.ReadLine());
        b=int.Parse(Console.ReadLine());
        c=int.Parse(Console.ReadLine());

        Console.WriteLine((a+b)%c+"\n"+((a%c)+(b+c))%c+"\n"+(a*b)%c+"\n"+((a*b)*(b*c))%c);
    }
}