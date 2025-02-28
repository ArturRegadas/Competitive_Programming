#include <stdio.h>

int main() {
    int repeat;
    scanf("%d", &repeat);
    int ans, size;
    for (int r = 0; r < repeat; r++) {
        ans = 0;
        scanf("%d", &size);
        int disparos[size];
        for (int i = 0; i < size; i++) scanf("%d", &disparos[i]);

        char jumps[size + 1];
        scanf("%s", jumps);

        for (int i = 0; i < size; i++) {
            if ((jumps[i] == 'S' && disparos[i] <= 2) || 
                (jumps[i] == 'J' && disparos[i] > 2)) {
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
