using System;

class if1{
    static void main(String[] args){
        int a = int.Parse(Console.ReadLine());
        int b = int.Parse(Console.ReadLine());

        if(a>b){
            Console.WriteLine(">");
        }
        else if(a<b){
            Console.WriteLine("<");
        }
        else{
            Console.WriteLine("==");
        }
    }
}