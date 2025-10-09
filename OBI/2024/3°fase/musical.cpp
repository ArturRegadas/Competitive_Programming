#include <bits/stdc++.h>

using namespace std;

int main(){
    int r;cin>>r;
    vector<int> nums(r);
    for(int i =0;i<r;i++)cin>>nums[i];
    sort(nums.begin(), nums.end(), greater<int>());
    int re=0;
    for(int i =1; i<r;i++){
        re+=nums[i-1]-nums[i];
    }
    cout<<re*2<<"\n";
    return 0;
}