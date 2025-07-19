#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, ps, pa;
    scanf("%d%d%d", &n, &ps, &pa);
    int ans = ((ps+pa)%n);
    if(ans == 0) ans = n;
    printf("%d", ans);

    return 0;
}