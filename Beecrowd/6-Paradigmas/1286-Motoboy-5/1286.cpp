#include <bits/stdc++.h>
using namespace std;

int main(){
    int pedidos, maxPizza;

    while(1){
        scanf("%d", &pedidos);if(!pedidos)return 0;
        vector<int> tmp(pedidos);
        vector<int> pizzas(pedidos);
        scanf("%d", &maxPizza);
        for(int i =0;i<pedidos;i++)scanf("%d%d", &tmp[i], &pizzas[i]);

        vector<vector<int>> dp(pedidos+1, vector<int>(maxPizza+1, 0 ));
        for(int i =0; i<pedidos;i++){
            for(int j =pizzas[i]; j<maxPizza;j++){
                dp[i+1][j+1] = max(dp[i][j+1], dp[i][j-pizzas[i]+1]+tmp[i]);
            }
        }
        for(int i =0; i<=pedidos;i++){
            for(int j =0; j<=maxPizza;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }

        printf("%d min.\n", dp[pedidos][maxPizza]);

    }
    
    return 0;
}