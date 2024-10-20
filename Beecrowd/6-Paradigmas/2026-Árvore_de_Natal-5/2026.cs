using System;

public class solution{
    static int max(int n1, int n2){
        if (n1 > n2){
            return n1;
        }   
        else{
            return n2;
        }
        
    }
    
    static int maxprice(int[] price, int[] weight, int repeat, int qtd_weight){
        int[]  maxinum=new int [qtd_weight+1];
        int curr_p, curr_w;
        for(int i = 0; i< repeat; i++){
            curr_p=price[i];
            curr_w=weight[i];

            for(int w = qtd_weight; w>curr_w-1; w--){
                maxinum[w]=max(maxinum[w], maxinum[w-curr_w]+curr_p);
            }
            
            
        }
        
        return maxinum[qtd_weight];
        
    }
    static void Main(){
        int repeat, size, castle;
        int tests=int.Parse(Console.ReadLine());
        for (int r=0; r<tests; r++){
             repeat = int.Parse(Console.ReadLine());
             size = int.Parse(Console.ReadLine());
             int[] prices = new int[repeat];
             int[] weights = new int[repeat];
             for (int i =0; i<repeat;i++){
                string[] data = Console.ReadLine().Split(' ');
                prices[i]=int.Parse(data[0]);
                weights[i]=int.Parse(data[1]);
             }
            
            
            Console.WriteLine("Galho "+ (r+1)+":");
            Console.WriteLine("Numero total de enfeites: "+maxprice(prices, weights, repeat, size));
            Console.WriteLine();


        }

    }

}