using System;

public class URI{
    public static void Main(){
        while(true){
            string[] read = Console.ReadLine().Split(' ');
            int l = int.Parse(read[0]);
            int c = int.Parse(read[1]);
            int r1 = int.Parse(read[2]);
            int r2 = int.Parse(read[3]);
            if(l==0 && c == 0 && r1 ==0 && r2 == 0)break;
            if(2*r1>l || 2*r1>c || 2*r2>l || 2*r2>c){
                Console.WriteLine("N");
                continue;
            }
            if(Math.Sqrt(Math.Pow(l-r1-r2, 2)+Math.Pow(c-r1-r2, 2))>=(r1+r2)){
                Console.WriteLine("S");
                continue;
            }
            Console.WriteLine("N");
        }
    }
}