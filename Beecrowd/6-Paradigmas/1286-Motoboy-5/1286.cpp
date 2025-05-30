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

        vector<vector<int>> dp(pedidos+1, vector<int>(maxPizza+1, 0));
        for(int i = 0; i < pedidos; i++){
            for(int j = 0; j <= maxPizza; j++){
                if(j >= pizzas[i])  
                    dp[i+1][j] = max(dp[i][j], dp[i][j - pizzas[i]] + tmp[i]);
                else
                    dp[i+1][j] = dp[i][j];  
            }
        }


        printf("%d min.\n", dp[pedidos][maxPizza]);

    }
    
    return 0;
}