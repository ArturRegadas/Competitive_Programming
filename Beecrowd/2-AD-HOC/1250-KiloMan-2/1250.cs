using System;

class Program {
    static void Main() {
        int repeat = int.Parse(Console.ReadLine());
        for (int r = 0; r < repeat; r++) {
            int ans = 0;
            int size = int.Parse(Console.ReadLine());
            int[] disparos = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            string jumps = Console.ReadLine();

            for (int i = 0; i < size; i++) {
                if ((jumps[i] == 'S' && disparos[i] <= 2) || 
                    (jumps[i] == 'J' && disparos[i] > 2)) {
                    ans++;
                }
            }
            Console.WriteLine(ans);
        }
    }
}
