#include <stdio.h>
int max(int a, int b){
    return (a>b)?a:b;
}

int main(){
    int pedidos, maxPizza;

    while(1){
        scanf("%d", &pedidos);if(!pedidos)return 0;
        int tmp[1000];
        int pizzas[1000];
        scanf("%d", &maxPizza);
        for(int i =0;i<pedidos;i++)scanf("%d%d", &tmp[i], &pizzas[i]);

        int dp[1000][1000];
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