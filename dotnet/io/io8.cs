using System;

class io8{
    static void main(string[] args){
        string[] s = Console.ReadLine().Split();
        Console.WriteLine(double.Parse(s[0])/double.Parse(s[1]));
    }
}