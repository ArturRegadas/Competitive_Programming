#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n;
    scanf("%lld", &n);
    vector<pair<ll, ll>> oni;
    ll c, p;
    for(ll i = 0; i<n; i++){
        scanf("%lld%lld", &c, &p);
        oni.push_back({c, 1});
        oni.push_back({p, 0});
    }

    sort(oni.begin(), oni.end());

    ll ans = 1;
    ll current = 0;
    for(pair<ll, ll> i : oni){
        if(i.second == 1){
            current++;
            ans=max(ans, current);

        }
        else{
            current--;
        }
    }
    printf("%lld\n", ans*20);

    return 0;
}