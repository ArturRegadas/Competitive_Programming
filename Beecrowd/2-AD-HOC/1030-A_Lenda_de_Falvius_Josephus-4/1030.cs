using System;

class Program {
    static int josephus(int n, int k){
        int ps=0;
        for(int i=2; i<=n; i++){
            ps=(ps+k)%i;
        }
        return ps+1;
    }
    public static void Main(string[] args) {
        int r=int.Parse(Console.ReadLine());
        for(int n=0; n<r; n++){
            string[] info=Console.ReadLine().Split(' ');
            int n1=int.Parse(info[0]);
            int k=int.Parse(info[1]);
            Console.WriteLine("Case {0}: {1}", n+1, josephus(n1, k));
        }
    }
}