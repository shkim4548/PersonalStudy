using System;

class io8{
    static void Main(string[] args){
        int a,b;
        a=int.Parse(Console.ReadLine());
        b=int.Parse(Console.ReadLine());

        Console.WriteLine(a+b);
        Console.WriteLine(a-b);
        Console.WriteLine(a*b);
        Console.WriteLine((float)a/b);
        Console.WriteLine(a%b);
    }
}