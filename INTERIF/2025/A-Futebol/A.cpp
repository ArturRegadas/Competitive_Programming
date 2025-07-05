#include <bits/stdc++.h>
using namespace std;

int main(){

    int nums[100];
    nums[0] = 0;
    int n;
    scanf("%d", &n);
    for(int i =1;i<n+1;i++){
        scanf("%d", &nums[i]);
    }
    int ans = 90;
    for(int i =1; i<n+1;i++){
        if(nums[i] - nums[i-1] > 15){
            ans = nums[i-1]+15;
        }
    }
    printf("%d\n", ans);

    return 0;
}