using System;

class Program {
    static void Main() {
        int T = int.Parse(Console.ReadLine());

        while (T-- > 0) {
            string[] valores = Console.ReadLine().Split();
            int N = int.Parse(valores[0]);
            int M = int.Parse(valores[1]);

            int[] blocos = Array.ConvertAll(Console.ReadLine().Split(), int.Parse);
            int[] dp = new int[M + 1];

            Array.Fill(dp, int.MaxValue);
            dp[0] = 0;

            foreach (int bloco in blocos) {
                for (int j = bloco; j <= M; j++) {
                    if (dp[j - bloco] != int.MaxValue) {
                        dp[j] = Math.Min(dp[j], dp[j - bloco] + 1);
                    }
                }
            }

            Console.WriteLine(dp[M]);
        }
    }
}
