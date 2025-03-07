//prefix sum com ponteiro
#include <bits/stdc++.h>
#define ll long long
#define MAXN (int)2e5+10
#define S second
#define F first
using namespace std;

ll n, h;
ll x1, x2;
ll ans =0;
pair<ll, ll> air[MAXN];
ll prefixSumAir[MAXN];
ll prefixSumFloor[MAXN];


int main(){
    scanf("%lld%lld", &n, &h);
    for(ll i =0;i<n;++i){
        scanf("%lld%lld", &x1, &x2);
        air[i] = {x1, x2};
    }
    prefixSumAir[0] = 0;
    prefixSumFloor[0] = 0;
    for(int i =1;i <= n;i++)prefixSumAir[i] = prefixSumAir[i-1]+air[i-1].S-air[i-1].F;
    for(int i =1;i < n;i++)prefixSumFloor[i] = prefixSumFloor[i-1]+air[i].F-air[i-1].S;
    
    
    prefixSumFloor[n] = 1000000010;
    int r =0;
    for(int l =0;l<n;l++){
        while(r<n && prefixSumFloor[r]-prefixSumFloor[l]<h )r++;
        ans=max(ans, prefixSumAir[r]-prefixSumAir[l]+h);
    }

    printf("%lld\n", ans);
    

    
}