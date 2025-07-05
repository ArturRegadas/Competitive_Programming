#include <bits/stdc++.h>
using namespace std;

int main(){
    int v, a, f, p;
    scanf("%d%d%d%d", &v, &a, &f, &p);
    vector<int> n = {a, f, p};
    sort(n.begin(), n.end());
    int ans=0;
    for(int i : n){
        if(v - i >=0){
            v-=i;
            ans++;
        }
        else{
            break;
        }
    }
    printf("%d\n", ans);

    return 0;
}