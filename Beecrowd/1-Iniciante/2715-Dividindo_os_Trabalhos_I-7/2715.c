#include <stdio.h>
#define ll long long
#define MAXN (int)1e6+10
#define true 1
#define false 0
ll abs(ll a){
    return (a<0)?a*-1:a;
}

int main(){
    int n, nuns[MAXN];
    while(scanf("%d", &n) == 1){
        for(int i =0;i<n;++i)scanf("%d", &nuns[i]);
        int l = 0, r = n-1;
        ll Ra = 0, G =0;
        int antR = true;
        while(l<r){
            
            if(Ra+nuns[l] <= G+nuns[r]){
                Ra+=nuns[l];
                l++;
                antR = true;
            }
            else{
                G+=nuns[r];
                r--;
                antR = false;
            }
        }
        if(Ra<G)Ra+=nuns[l];
        else G += nuns[l];
        printf("%lld\n", abs(Ra - G));
        
    }
    return 0;
}