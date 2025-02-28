import java.util.*;

public class Main{
    public static void main(String[] args){

        int pedidos, m;
        Scanner sc = new Scanner(System.in);
        while(true){
            pedidos = sc.nextInt();
            if(0 ==pedidos)break;
            int[] tmp = new int[pedidos];
            int[] pizzas = new int[pedidos];
            int maxPizza = sc.nextInt();
            for(int i =0;i<pedidos;i++){
                tmp[i] = sc.nextInt();
                pizzas[i] = sc.nextInt();
            }

            int[][] dp = new int[pedidos+1][maxPizza+1];
            for(int i = 0; i < pedidos; i++){
                for(int j = 0; j <= maxPizza; j++){
                    if(j >= pizzas[i])  
                        dp[i+1][j] = Math.max(dp[i][j], dp[i][j - pizzas[i]] + tmp[i]);
                    else
                        dp[i+1][j] = dp[i][j];  
                }
            }


            System.out.printf("%d min.\n", dp[pedidos][maxPizza]);

        }
    }

}

