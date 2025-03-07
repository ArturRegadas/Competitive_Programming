#include <bits/stdc++.h>
#define MAXN (int)1e9+10
using namespace std;


int getFact(int n){
    if(n<=1)return 1;
    return n*getFact(n-1);

}

int main(){
    int v, x;
    scanf("%d%d", &v, &x);
    printf("%d\n", getFact(min(v, x)));

    return 0;
}