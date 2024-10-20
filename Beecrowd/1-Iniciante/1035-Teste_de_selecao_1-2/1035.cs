using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        string[] x = Console.ReadLine().Split(' ');
        
        int a = int.Parse(x[0]);
        int b = int.Parse(x[1]);
        int c = int.Parse(x[2]);
        int d = int.Parse(x[3]);
        
        if (b > c & d > a & c+d > a+b & c>0 & d>0 & a%2==0){
            Console.WriteLine("Valores aceitos");
        }
        else{
            Console.WriteLine("Valores nao aceitos");
        }
    }
}