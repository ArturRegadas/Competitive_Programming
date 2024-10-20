using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        string[] x = Console.ReadLine().Split(' ');
        
        double a = double.Parse(x[0]);
        double b = double.Parse(x[1]);
        double c = double.Parse(x[2]);
        
        if (a == 0 | b*b-4*a*c <0){
            Console.WriteLine("Impossivel calcular");
        }
        else{
            Console.WriteLine($"R1 = {(-b+Math.Pow((b*b-4*a*c), 0.5))/(2*a):f5}");
            Console.WriteLine($"R2 = {(-b-Math.Pow((b*b-4*a*c), 0.5))/(2*a):f5}");
        }
        
    
        
    }
}