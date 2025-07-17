#include <bits/stdc++.h>
using namespace std;

int main(){
    int e, m, d;
    scanf("%d%d%d", &e, &m, &d);
    vector<pair<int, int>> junt(m);
    vector<pair<int, int>> sep(d);
    vector<int> est(e);
    for(int i =0;i<m; i++)
        scanf("%d%d", &junt[i].first, &junt[i].second);
    
    for(int i =0;i<d; i++)
        scanf("%d%d", &sep[i].first, &sep[i].second);

    int a, b, c;
    for(int i =0; i<(int)e/3; i++){
        scanf("%d%d%d", &a, &b, &c);
        est[a-1] = i;
        est[b-1] = i;
        est[c-1] = i;
    }
    int ans = 0;
    for(pair<int, int> i: junt){
        if(est[i.first -1] != est[i.second -1])
            ans++;
    }
    for(pair<int, int> i:sep){
        if(est[i.first -1] == est[i.second -1])
            ans++;
    }
    printf("%d\n", ans);
}