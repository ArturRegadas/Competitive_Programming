#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

void reverse(int *arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

int main() {
    int idx, midle, ans, ans2, size, cases;
    scanf("%d", &cases);
    
    for (int r = 0; r < cases; r++) {
        scanf("%d", &size);
        int nuns[size], newNuns[size], newNuns2[size];

        for (int i = 0; i < size; i++) {
            scanf("%d", &nuns[i]);
        }

        qsort(nuns, size, sizeof(int), compare);

        midle = size / 2;
        if (size % 2 == 0) midle--;

        ans = 0;
        idx = 0;
        for (int i = size - 1; i > midle; i--) {
            newNuns[idx] = nuns[i - midle - 1];
            idx++;
            newNuns[idx] = nuns[i];
            idx++;
        }

        if (size % 2 == 1) newNuns[idx] = nuns[midle];

        for (int i = 1; i < size; i++) {
            ans += abs(newNuns[i - 1] - newNuns[i]);
        }

        reverse(nuns, size);

        idx = 0;
        for (int i = size - 1; i > midle; i--) {
            newNuns2[idx] = nuns[i - midle - 1];
            idx++;
            newNuns2[idx] = nuns[i];
            idx++;
        }

        ans2 = 0;
        if (size % 2 == 1) newNuns2[idx] = nuns[midle];

        for (int i = 1; i < size; i++) {
            ans2 += abs(newNuns2[i - 1] - newNuns2[i]);
        }

        printf("Case %d: %d\n", r + 1, max(ans, ans2));
    }

    return 0;
}
