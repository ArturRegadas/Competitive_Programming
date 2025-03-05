#include <stdio.h>
#include <math.h>
#define true 1
#define false 0
int max(int a, int b){return (a>b)? a:b;}
int main(){
    int cases, size, water, maxKey;
    double totalW, totalP;
    int c =1;
    int first = true;
    while(1){
        scanf("%d", &cases);
        if(cases==0)return 0;
        if(!first)printf("\n");
        first = false;
        int city[210] ={0};
        totalW = 0;
        totalP= 0;
        maxKey=0;
        for(int i=0;i<cases;i++){
            scanf("%d%d", &size, &water);
            totalP += size;
            totalW +=water;
            maxKey = max(maxKey, water/size);
            city[water/size] += size;  
        }
        printf("Cidade# %d:\n", c);
        for(int i =0;i<maxKey; i++){
            if(city[i] != 0)printf("%d-%d ", city[i], i);
        }
        printf("%d-%d\n", city[maxKey], maxKey);
        printf("Consumo medio: %.2lf m3.\n", floor((totalW/totalP)*100)/100);
        c++;
    }
}