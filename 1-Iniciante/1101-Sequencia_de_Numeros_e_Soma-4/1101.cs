using System;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        while(true){
            string[] nuns = Console.ReadLine().Split(' ');
            int nun1 = int.Parse(nuns[0]);
            int nun2 = int.Parse(nuns[1]);
            if(nun1 <= 0 | nun2 <= 0){
                break;
            }
            int total = 0;
            if(nun1>nun2){
                for(int i=nun2; i<nun1+1; i++){
                    total+=i;
                    Console.Write($"{i} ");
                }
            }
            else{
                for(int u=nun1; u<nun2+1; u++){
                    total+=u;
                    Console.Write($"{u} ");
                }
            }
            Console.WriteLine($"Sum={total}");
    
        }
    }
}