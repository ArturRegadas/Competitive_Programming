#include <bits/stdc++.h>
#define MAXN 1e3+10
using namespace std;

set<int> getDiv(int n){
    set<int> ans;
    for(int i =2;i<=floor(sqrt(n))+1;++i){
        if(n%2==0)ans.insert(i);
    }
    return ans;
}

int main(){
    bool ans;
    int n, a, b;
    int vals[2];
    scanf("%d", &n);
    for(int i =1; i<n;i++){
        a=i;b=n-i;
        if(a>=b)break;
        set<int> da =  getDiv(a);
        set<int> db = getDiv(b);
        ans=true;
        for(int i : da){
            if(db.find(i)!= db.end()){
                ans=false;
                break;
            }
        }
        if(ans){
            vals[0] = a;
            vals[1] = b;
        }
    }
    printf("%d %d\n", vals[0], vals[1]);
    return 0;
}