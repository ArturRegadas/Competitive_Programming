#include <stdio.h>

int lower_bound(int *arr, int size, int target) {
    int l = 0, r = size;
    while (l < r) {
        int mid = (l + r) / 2;
        if (arr[mid] < target) l = mid + 1;
        else r = mid;
    }
    return l;
}

int LIS(int *nums, int n) {
    int lis[1000001], length = 0;
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(lis, length, nums[i]);
        if (pos == length) lis[length++] = nums[i];
        else lis[pos] = nums[i];
    }
    return length;
}

int main() {
    int n, nums[1000001];
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        printf("%d\n", LIS(nums, n));
    }
    return 0;
}
