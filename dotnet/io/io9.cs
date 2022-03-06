using System;

class io9{
    static void  main(string[] args){
        string[] s = Console.ReadLine().Split();

        Console.WriteLine(int.Parse(s[0])+int.Parse(s[1]));
        Console.WriteLine(int.Parse(s[0])-int.Parse(s[1]));
        Console.WriteLine(int.Parse(s[0])*int.Parse(s[1]));
        Console.WriteLine(int.Parse(s[0])/int.Parse(s[1]));
        Console.WriteLine(int.Parse(s[0])%int.Parse(s[1]));
    }
}