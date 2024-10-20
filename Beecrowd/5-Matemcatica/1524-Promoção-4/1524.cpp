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
    int repeat, p1, p2, size;
    while (1){
        std::cin>>repeat;
        if (repeat==0){
            break;
        }
        int prices[repeat];
        int weights[repeat];

        for (int r =0; r<repeat; r++){
            std::cin>>p1>>p2;

            prices[r]=p1;
            weights[r]=p2;

        }

        std::cin>>size;

        std::cout<<maxnum(prices, weights, repeat, size)<<"\n";

    }

    return 0;
}