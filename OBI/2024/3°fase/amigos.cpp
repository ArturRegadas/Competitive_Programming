#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> a1;
    vector<int> a2;
    int v;
    for(int i = 0; i<n;i++){
        scanf("%d", &v);
        if(v)
            a1.push_back(i);
    }
    for(int i = 0; i<n;i++){
        scanf("%d", &v);
        if(v)
            a2.push_back(i);
    }

    long long ans = 0;
    for(int i = 0; i<m;i++)
        ans+= abs(a1[i] - a2[i]);
    printf("%lld\n", ans);
}