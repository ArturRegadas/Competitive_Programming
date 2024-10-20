using System;


class solution {
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
    
    public static void Main(string[] args) {
        while (true){
            int repeat = int.Parse(Console.ReadLine());
            if (repeat ==0){
                break;
            }

            int[] price = new int[repeat];
            int[] weight = new int[repeat];

            for (int r=0; r< repeat;r++){
                string[] data=Console.ReadLine().Split(' ');
                
                price[r]=int.Parse(data[0]);
                weight[r]=int.Parse(data[1]);
            }

            int qtd_weight=int.Parse(Console.ReadLine());
            Console.WriteLine(maxprice(price, weight, repeat, qtd_weight));
                   
         }
    }
}
