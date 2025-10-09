#include <bits/stdc++.h>
#define INF (long long)1e18+10
#define ll long long
using namespace std;

ll min(ll a, ll b){
    if(a < b)
        return a;
    else
        return b;
}

int main(){
    ll n, d;
    scanf("%lld%lld", &n, &d);
    vector<ll> dolls(n);
    for(int i = 0; i<n; i++)
        scanf("%lld", &dolls[i]);
    
    sort(dolls.begin(), dolls.end());
    vector<vector<ll>> dp(n+1, vector<ll>(d+1, 0));
    /*
    usaded if (d-j)*3 < n-i
    (dolls, qtd_trios)
    [      6    3    0
    7    [INF, INF, INF],
    6    [0,    1,   1 ],
    5    [0,    1,   1 ],
    4    [0,    1,   1 ],
    3    [0,    0,   1 ],
    2    [0,    0,   1 ],
    1    [0,    0,   1 ],
    0    [0,    0,   0 ],
    ]
    dp[i][j] = min(
        dp[i-1][j], // a de cima 
        dp[i-2][j-1] + dolls[i] - dolls[i-1]
    )
    */

    for(int i = 1; i<=d; i++)
        dp[0][i] = INF;
    for(ll i = 1; i<= n; i++){
        for(ll j = 0; j<=d;j++){
            if((d-j)*3 < n-i && i > 1 && j > 0){
                dp[i][j] = min(
                    dp[i-1][j],
                    dp[i-2][j-1] + pow(dolls[i-1] - dolls[i-2], 2)
                );
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    printf("%lld\n", dp[n][d]);

    return 0;
}