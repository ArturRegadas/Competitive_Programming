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
    int repeat, datap, dataw, size;
    while(1){
        
        scanf("%d", &repeat);
        if(repeat==0){
            break;
        }

        int price[repeat], weight[repeat];
        
        for(int r=0;r<repeat; r++){
            scanf("%d",&datap);
            scanf("%d",&dataw);
            price[r]=datap;
            weight[r]=dataw;
        }

        scanf("%d", &size);
        printf("%d\n", maxprice(price, weight, repeat, size));

    }
        

    return 0;
}