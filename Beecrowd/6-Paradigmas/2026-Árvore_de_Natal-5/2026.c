#include <stdio.h>

int max(int n1, int n2){
    if(n1>n2){
        return n1;
    }
    else{
        return n2;
    }
}

int maxprice(int price[], int weight[], int repeat, int size){
    int maxinum[size+1];
    for (int i = 0; i <= size; i++) {
        maxinum[i] = 0;
    }

    int currp, currw;

    for(int i=0; i<repeat; i++){
        currp=price[i];
        currw=weight[i];

        for(int w=size; w>currw-1; w--){
            maxinum[w]=max(maxinum[w], maxinum[w-currw]+currp);
        }

    }

    return maxinum[size];
}

int main(){
    int tests, repeat, p1, p2, size, castle;
    scanf("%d",&tests);

    for(int r=0; r<tests; r++){
        scanf("%d", &repeat);
        scanf("%d", &size);
        int prices[repeat];
        int weights[repeat];
        for(int i=0; i<repeat; i++){
            scanf("%d", &p1);
            scanf("%d", &p2);
            prices[i]=p1;
            weights[i]=p2;
        }
    

    printf("Galho %d:\n", r+1);
    printf("Numero total de enfeites: %d\n\n",maxprice(prices, weights, repeat, size));

    }
    
    

    return 0;
}