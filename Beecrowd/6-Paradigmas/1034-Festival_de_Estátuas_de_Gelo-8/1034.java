import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        
        while (T-- > 0) {
            int N = sc.nextInt();
            int M = sc.nextInt();
            
            int[] blocos = new int[N];
            for (int i = 0; i < N; i++) {
                blocos[i] = sc.nextInt();
            }
            
            int[] dp = new int[M + 1];
            Arrays.fill(dp, Integer.MAX_VALUE);
            dp[0] = 0;

            for (int bloco : blocos) {
                for (int j = bloco; j <= M; j++) {
                    if (dp[j - bloco] != Integer.MAX_VALUE) {
                        dp[j] = Math.min(dp[j], dp[j - bloco] + 1);
                    }
                }
            }

            System.out.println(dp[M]);
        }
        
        sc.close();
    }
}
