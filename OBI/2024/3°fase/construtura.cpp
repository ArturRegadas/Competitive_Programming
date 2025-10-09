#include <bits/stdc++.h>
#define INF 10000
using namespace std;

int minI(vector<int> arr){
    int m = INF;
    int ans = -1;
    for(int i = 0; i< arr.size(); i++){
        if(arr[i] < m){
            m = arr[i];
            ans = i;
        }
    }
    return ans;
}

int maxV(vector<int> arr){
    int ans = -INF;
    for(int i : arr){
        if(i > ans)
            ans = i;
    }
    return ans;
}

int main(){
    int n;
    scanf("%d", &n);
    vector<int> nums(n);
    for(int i =0; i<n; i++)
        scanf("%d", &nums[i]);

    int max = maxV(nums);
    int ans = 0;
    int minIdx;
    while(1){
        minIdx = minI(nums);
        if(nums[minIdx] == max)
            break;
        bool flag = false;
        while(minIdx+1 < n && nums[minIdx] == nums[minIdx+1]){
            nums[minIdx]++;
            minIdx++;
            flag = true;
        }
        nums[minIdx]++;
        ans ++;
        
    }
    printf("%d\n", ans);

    return 0;
}