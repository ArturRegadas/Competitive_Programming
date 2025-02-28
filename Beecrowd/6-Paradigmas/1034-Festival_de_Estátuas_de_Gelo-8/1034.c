#include <stdio.h>

#define MAX 1001000

int main() {
    int r;
    scanf("%d", &r);
    int n, m;
    
    for (int i = 0; i < r; i++) {
        scanf("%d%d", &n, &m);
        int dp[m + 1];
        
        for (int j = 0; j <= m; j++)
            dp[j] = MAX;
        
        dp[0] = 0;
        int current;
        
        for (int j = 0; j < n; j++) {
            scanf("%d", &current);
            for (int k = 0; k < m; k++) {
                if (current <= k + 1) {
                    if (dp[k - current + 1] + 1 < dp[k + 1])
                        dp[k + 1] = dp[k - current + 1] + 1;
                }
            }
        }
        
        printf("%d\n", dp[m]);
    }

    return 0;
}
