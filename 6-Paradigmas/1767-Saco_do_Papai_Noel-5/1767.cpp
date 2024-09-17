#include <iostream>
#include <vector>

int toykg(int maxinum[], int maxp, int size){
    int l=size;
    while (maxinum[l] == maxp){
        l-=1;}
    return l+1;
}


std::vector<int> maxnum(int prices[],int weights[],int repeat,int size){

    int maxinum[size+1]={0};
    int itens[size+1]={0};
    int current_price, current_weight;

    for (int i =0; i< repeat; i++){
        current_price=prices[i];
        current_weight=weights[i];

        for(int w = size; w > current_weight-1; w--){
            if(maxinum[w-current_weight]+current_price > maxinum[w]){
                maxinum[w]=maxinum[w-current_weight]+current_price;
                itens[w]=itens[w-current_weight]+1;
            }
            
        }

    }
    int toyk = toykg(maxinum, maxinum[size], size);
    std::vector<int> l= {maxinum[size], itens[size], toyk};
    return l;
}

int main(){
    int tests, repeat, size, castle;
    std::cin>>tests;
    for(int r=0; r< tests; r++){
        std::cin>>repeat;
        int prices[repeat];
        int weights[repeat];
        for(int i=0; i< repeat; i++){
            std::cin>>prices[i]>>weights[i];
        }
        
        std::vector<int> k=maxnum(prices, weights, repeat, 50);

        std::cout<<k[0]<<" brinquedos\n";
        std::cout<<"Peso: "<<k[2]<<" kg\n";
        std::cout<<"sobra(m) "<<repeat-k[1]<<" pacote(s)\n\n";

    }
    

    return 0;
}