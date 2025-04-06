#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int LIS(vector<int> nums){
    vector<int> ans;
    for(int i : nums){
        auto it = lower_bound(ans.begin(), ans.end(), i);
        if(it == ans.end())ans.push_back(i);
        else *it = i;
    }
    return ans.size();
}

int main(){
    int n;
    while(scanf("%d", &n)!= EOF){
        vector<int> nums(n);
        for(int i =0;i<n;i++)scanf("%d", &nums[i]);
        printf("%d\n", LIS(nums));
    }
    
    return 0;
}