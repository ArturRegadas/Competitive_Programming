#include <bits/stdc++.h>
#define MAXN (int)1e6+10
using namespace std;

int main(){
    int n, nuns[MAXN];
    while(scanf("%d", &n) == 1){
        for(int i =0;i<n;++i)scanf("%d", &nuns[i]);
        int l = 0, r = n-1;
        sort(nuns, nuns+n);
        int R = nuns[0], G =nuns[r];
        l++;r--;
        if(n==1){
            printf("%d\n", nuns[0]);
            continue;
        }
        while(l<r){
            if(R+nuns[l] <= G){
                R+=nuns[l];
                l++;
            }
            else{
                G+=nuns[r];
                r--;
            }
        }
        printf("%d\n", abs(R-G));
        
    }
    return 0;
}