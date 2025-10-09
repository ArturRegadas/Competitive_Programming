#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll pa(ll init, ll end){
    if((end - init) % 2 == 0)
        return (init + end) * ((end-init)/2) + (end+init) / 2;
    return (init+end)*((end-init+1)/2);
}

int main(){
    ll a, b, l;
    int p;
    scanf("%d", &p);
    for(int i =0; i<p; i++){
        scanf("%lld%lld%lld",&l ,&a, &b);

        //binary search
        ll init = a;
        ll ans = a;
        while(a < b){
            ll mid = (a+b)/2;
            if(pa(init, mid) >= l){
                b = mid;
            }
            else{// pa(init, mid) > l
                a = mid+1;
            }
        }
        printf("%lld\n", a - init + 1);
    }

    return 0;
}