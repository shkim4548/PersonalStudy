using System;

class Program{
    static void main(String[] args){
        int a;
        a=int.Parse(Console.ReadLine());

        if(a>=90 && a<=100){
            Console.WriteLine("A");
        }
        else if(a>=80 && a<90){
            Console.WriteLine("B");
        }
        else if(a>=70 && a<80){
            Console.WriteLine("C");
        }
        else if(a>=60 && a<70){
            Console.WriteLine("D");
        }
        else{
            Console.WriteLine("F");
        }
    }
}