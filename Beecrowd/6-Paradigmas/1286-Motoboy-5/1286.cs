using System;

public class Solution{
    public static void Main(){

        int pedidos, m;

        while(true){
            pedidos = int.Parse(Console.ReadLine());
            if(0 ==pedidos)break;
            int[] tmp = new int[pedidos];
            int[] pizzas = new int[pedidos];
            int maxPizza = int.Parse(Console.ReadLine());
            for(int i =0;i<pedidos;i++){
                string[] aux = Console.ReadLine().Split(' ');
                tmp[i] = int.Parse(aux[0]);
                pizzas[i] = int.Parse(aux[1]);
            }

            int[,] dp = new int[pedidos+1, maxPizza+1];
            for(int i = 0; i < pedidos; i++){
                for(int j = 0; j <= maxPizza; j++){
                    if(j >= pizzas[i])  
                        dp[i+1, j] = Math.Max(dp[i, j], dp[i, j - pizzas[i]] + tmp[i]);
                    else
                        dp[i+1, j] = dp[i, j];  
                }
            }


            Console.WriteLine("{0} min.", dp[pedidos, maxPizza]);

        }
    }

}

