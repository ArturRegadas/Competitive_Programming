#include <iostream>

int maxi(int n1, int n2){
    if (n1>n2){
        return n1;
    }
    else{
        return n2;
    }
}

int maxnum(int prices[],int weights[],int repeat,int size){

    int maxinum[size+1]={0};
    int current_price, current_weight;

    for (int i =0; i< repeat; i++){
        current_price=prices[i];
        current_weight=weights[i];

        for(int w = size; w > current_weight-1; w--){
            maxinum[w]=maxi(maxinum[w], maxinum[w-current_weight]+current_price);
        }

    }

    return maxinum[size];
}

int main(){

    int tests, repeat, size, castle;
    std::cin>>tests;
    for(int r=0; r< tests; r++){
        std::cin>>repeat;
        std::cin>>size;
        int prices[repeat];
        int weights[repeat];
        for(int i=0; i< repeat; i++){
            std::cin>>prices[i]>>weights[i];
        }
        
        std::cout<<"Galho "<<r+1<<":\n";
        std::cout<<"Numero total de enfeites: "<<maxnum(prices, weights, repeat, size)<<"\n\n";


    }

    return 0;
}