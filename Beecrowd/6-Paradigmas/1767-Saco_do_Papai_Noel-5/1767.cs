using System;

class soluton{

    static int minkg(int[] maxinum, int maxp, int q){
        int l = q;
        while(maxinum[l]==maxp){
            l--;
        }
        return l+1;
    }

    
    static int[] maxprice(int[] price, int[] weight, int repeat, int qtd_weight){
        int[]  maxinum=new int [qtd_weight+1];
        int[] itens=new int[qtd_weight+1];
        int curr_p, curr_w;
        for(int i = 0; i< repeat; i++){
            curr_p=price[i];
            curr_w=weight[i];

            for(int w = qtd_weight; w>curr_w-1; w--){
                if (maxinum[w-curr_w]+curr_p > maxinum[w]){
                    maxinum[w]=maxinum[w-curr_w]+curr_p;
                    itens[w]=itens[w-curr_w]+1;
                }
            }
        }
        int toysk= minkg(maxinum, maxinum[qtd_weight], qtd_weight);
        int[] r={maxinum[qtd_weight], itens[qtd_weight], toysk};
        return r;
        
    }

    static void Main(){

        int tests = int.Parse(Console.ReadLine());
        for(int r=0; r< tests; r++){
            int repeat = int.Parse(Console.ReadLine());
            int[] prices = new int[repeat];
            int[] weights = new int[repeat];
            for (int i=0; i<repeat; i++){
                string[] data = Console.ReadLine().Split(' ');
                prices[i]=int.Parse(data[0]);
                weights[i]=int.Parse(data[1]);
            }
            int r1,r2,r3;
            int[] ra=maxprice(prices, weights, repeat, 50);

            Console.WriteLine(ra[0]+" brinquedos");
            Console.WriteLine("Peso: "+ra[2]+" kg");
            Console.WriteLine("sobra(m) "+(repeat-ra[1])+" pacote(s)");
            Console.WriteLine();
            
        }

    }
}