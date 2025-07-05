#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if (n == 2)return true;
    for(int i = 2; i<(int)sqrt(n)+1; i++){
        if(n%i==0)
            return false;
    }
    return true;
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = m; i>=n;i--){
        if(isPrime(i)){
            printf("%d\n", i);
            return 0;
        }
    }

    return 0;
}