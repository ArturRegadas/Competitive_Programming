#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, g, m;
    scanf("%d%d%d", &n, &g, &m);

    int ans=((g*8)+(m*6))%n;
    if((g*8)+(m*6)>n)
        printf("%d\n", ans);
    else
        printf("0\n");
    

    return 0;
}