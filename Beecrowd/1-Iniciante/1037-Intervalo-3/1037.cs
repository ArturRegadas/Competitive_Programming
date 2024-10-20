using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        double onun = double.Parse(Console.ReadLine());
        
        if (onun>=0 & onun <=25){
            Console.WriteLine("Intervalo [0,25]");
        }
        else if (onun>25 & onun <=50){
            Console.WriteLine("Intervalo (25,50]");
        }
        else if (onun>50 & onun <=75){
            Console.WriteLine("Intervalo (50,75]");
        }
        else if (onun>75 & onun <=100){
            Console.WriteLine("Intervalo (75,100]");
        }
        else{
            Console.WriteLine("Fora de intervalo");
        }
    }
}