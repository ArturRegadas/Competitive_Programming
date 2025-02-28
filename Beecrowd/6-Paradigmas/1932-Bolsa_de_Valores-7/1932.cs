using System;
using System.Linq;

public class Solution {
    public static void Main(String[] args){
        int s, t, ant, current, ans;
        string[] aux = Console.ReadLine().Split(' ');
        s=int.Parse(aux[0]);
        t=int.Parse(aux[1]);
        int[] days = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        ans = 0;
        ant = current = days[0];
        for(int i =1;i<s;++i){
            if((current>days[i] && current-days[i]>=t) || ant>days[i]){
                ans = Math.Max(ans, ans+current-ant-t);
                current = ant = days[i];
            }
            if(days[i]>current)current=days[i];
        }
        ans=Math.Max(ans, ans+current-ant-t);
        Console.WriteLine(ans);

    }
}
