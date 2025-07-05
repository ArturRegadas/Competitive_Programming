#include <bits/stdc++.h>

using namespace std;

int main(){

    int a, b, c, d;
    //se a <= c-*d <= b
    scanf("%d%d%d%d", &a, &b, &c, &d);

    for(int i = c; i>=a; i-=d){
        if (i<=b){
            printf("S\n");
            return 0;
        }
    }
    printf("N\n");
    return 0;
}