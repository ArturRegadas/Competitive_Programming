//Solve with bitmask
//bitSet armazena bites bin mas sao mais otimizados que bool
//por ser uma classe facilita operacoes
#include <cstdio>
#include <iostream>
#include <bitset>
#define ll long long
#define MAXN 155
#define INF 300001
using namespace std;

ll nums[MAXN];

ll getMaxSum(ll n, ll total){
        bitset<INF> dp;
        dp[0] = 1;
        for(int i=0;i<n;i++){
            dp |= ( dp << nums[i]);
        }
        ll midle = total/2;
        for(ll i = midle; i>=0; i--){
            if(dp[i])return total - 2*i;
        }
        return 0;
}

int main(){
    ll n, total;
    while (scanf("%lld", &n) == 1){
        total = 0;
        for(int i =0;i<n;i++){
            scanf("%lld", &nums[i]);
            total+=nums[i];
        }
        printf("%lld\n", getMaxSum(n, total)); 
    }
}
