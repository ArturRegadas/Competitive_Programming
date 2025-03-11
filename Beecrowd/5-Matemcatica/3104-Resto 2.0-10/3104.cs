using System;

public class Solution{
    public static void Main(){
        string A = Console.ReadLine();
        long B = long.Parse(Console.ReadLine());

        long ans = 0;
        foreach(char c in A){
            ans = (ans*10 + ((long)c - (long)'0'))%B;
        }
        Console.WriteLine(ans);
    }
}