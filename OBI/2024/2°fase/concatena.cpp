#include <bits/stdc++.h>
using namespace std;
/*
Ao concatenar dois dígitos 
𝑎
a e 
𝑏
b, o número gerado é:
10
⋅
𝑎
+
𝑏
10⋅a+b
*/
long long nums[100010];
long long pref[100010];

int main(){
    long long n, m;
    scanf("%lld%lld", &n, &m);
    for(long long i =0; i<n;i++)
        scanf("%d", &nums[i]);
    
    for(long long i =0; i<n;i++){
        pref[i+1] = pref[i] + nums[i];
    }

    long long l, r;
    for(long long i =0; i<m; i++){
        scanf("%lld%lld", &l, &r);
        printf("%lld\n", (pref[r] - pref[l-1]) * 11 * (r-l) );
    }

    return 0;
}