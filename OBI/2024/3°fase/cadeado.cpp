#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> cad(n);
    for(int i =0; i<n; i++)
        scanf("%d%d", &cad[i].first, &cad[i].second);
    
    int ans = 0;
    for(pair<int, int> i : cad){
        int delta = abs(i.first - i.second);
        if ( delta <= 5)
            ans += delta;
        
        else
            ans += 10-delta;
    }
    printf("%d\n", ans);
        
    return 0;
}