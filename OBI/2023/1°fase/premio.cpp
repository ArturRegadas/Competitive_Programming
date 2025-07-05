#include <bits/stdc++.h>
using namespace std;

int main(){
    int p, d, b;
    scanf("%d%d%d", &p, &d, &b);
    int ans = p + d*2 + b*3;
    if(ans >= 150 ){
        printf("B\n");
    }
    else if(ans >=120){
        printf("D\n");
    }
    else if (ans>=100){
        printf("P\n");
    }
    else{
        printf("N\n");
    }

    return 0;
}