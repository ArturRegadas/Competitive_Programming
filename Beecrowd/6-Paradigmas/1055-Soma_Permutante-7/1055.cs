using System;
using System.Linq;


public class Solution{
    public static void Main(){
        int idx, midle, ans,ans2, size, cases;
        cases = int.Parse(Console.ReadLine());
        for(int r = 0;r<cases;r++){
            int[] nuns = Console.ReadLine().Split(' ').Skip(1).Select(int.Parse).ToArray();
            size = nuns.Length;
            Array.Sort(nuns);
            int[] newNuns = new int[size];
            midle = (size/2);
            if(size%2==0)midle--;
            ans = 0;
            idx=0;
            for(int i = size-1; i>midle; i--){
                newNuns[idx] = nuns[i-midle-1];
                idx++;
                newNuns[idx] = nuns[i];
                idx++;
            }
            
            if(size%2==1)newNuns[idx] = nuns[midle];
            for(int i =1;i<size;++i)ans+= Math.Abs(newNuns[i-1] - newNuns[i]);


            Array.Reverse(nuns);
            idx=0;
            int[] newNuns2 = new int[size];
            for(int i = size-1; i>midle; i--){
                newNuns2[idx] = nuns[i-midle-1];
                idx++;
                newNuns2[idx] = nuns[i];
                idx++;
            }
            ans2 =0;
            if(size%2==1)newNuns2[idx] = nuns[midle];
            for(int i =1;i<size;++i)ans2+= Math.Abs(newNuns2[i-1] - newNuns2[i]);
            
            
            
            Console.WriteLine("Case {0}: {1}", r+1, Math.Max(ans, ans2));
        }

    }
}
