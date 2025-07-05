#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int r = n/400;
    printf("%d\n", min(abs(n-(r*400)), abs(n-((r+1)*400))));
    return 0;
}