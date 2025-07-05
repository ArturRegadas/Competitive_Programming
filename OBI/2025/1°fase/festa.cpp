#include <bits/stdc++.h>

using namespace std;

int main(){

    int e, s, l;
    scanf("%d%d%d", &e, &s, &l);

    printf("%d\n", abs(e-s)+abs(s-l)+abs(l-e));

    return 0;
}