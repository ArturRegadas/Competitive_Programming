#include <bits/stdc++.h>
#define MAXN (int)1e5+10
#define pb push_back
using namespace std;


int main(){
    int t, n, k;
    scanf("%d", &t);
    for(int c =0;c<t;++c){
        int nuns[MAXN];
        scanf("%d%d", &n, &k);
        for(int i =0;i<n;++i)scanf("%d", &nuns[i]);

        int ans =0;

        vector<int> Minus;
        vector<int> Maxi;
        for(int i =0;i<n;++i){
            while(!Minus.empty() && Minus[0] < i-k-1) Minus.erase(Minus.begin());
            while(!Maxi.empty() && Maxi[0] < i-k-1)Maxi.erase(Maxi.begin());

            while(!Minus.empty() && nuns[Minus.back()] >= nuns[i])Minus.pop_back();
            Minus.pb(i);
            while(!Maxi.empty() && nuns[Maxi.back()] <= nuns[i])Maxi.pop_back();
            Maxi.pb(i);

            ans = max(ans, nuns[Maxi[0]] - nuns[Minus[0]]);

        }
        
    
        printf("%d\n", ans);
    }


    return 0;
}