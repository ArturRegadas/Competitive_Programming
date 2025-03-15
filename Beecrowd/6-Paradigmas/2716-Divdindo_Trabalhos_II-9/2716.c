#include <stdio.h>
#include <string.h>

#define MAX_SUM 150000  // 150 * 2000 / 2

int dp[MAX_SUM + 1];

int main() {
    int n, values[150];

    while (scanf("%d", &n) != EOF) {
        int total = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &values[i]);
            total += values[i];
        }

        int mid = total / 2;
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = mid; j >= values[i]; j--) {
                dp[j] |= dp[j - values[i]];
            }
        }

        for (int i = mid; i >= 0; i--) {
            if (dp[i]) {
                printf("%d\n", total - 2 * i);
                break;
            }
        }
    }
    return 0;
}
