#include <bits/stdc++.h>
using namespace std;

int nums[100010];
bool in[100010];

int main(){
    int n;
    scanf("%d", &n);
    for(int i =0; i<n;i++)
        scanf("%d", &nums[i]);

    int l = 0;
    int r =1;
    int ans =1;
    in[nums[0]] = true;
    for(int r =1; r<n;){
        //se tiver 
        if(in[nums[r]]){
            in[nums[l]] = false;
            l++;
        }
        else{
            in[nums[r]] = true;
            r++;
            ans = max(ans, r-l);
        }
    }
    printf("%d\n", ans);
}