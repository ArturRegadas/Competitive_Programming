#include <stdio.h>
#include <math.h>
int max(int a, int b){if(a>b)return a;
else b;}
int min(int a, int b){if(a>b)return b;
    else a;}
int main(){

    int l, c, r1, r2;
    while(1){
        scanf("%d%d%d%d", &l, &c, &r1, &r2);
        if(l==0 && c ==0 && r1==0 && r2 ==0){
            return 0;
        }

        if(2*r1>l || 2*r1>c || 2*r2>l || 2*r2>c){
            printf("N\n");
            continue;
        }
        if(sqrt(pow(l-r1-r2, 2) + pow(c-r1-r2, 2)) >= (r1+r2)){
            printf("S\n");
            continue;
        }
        printf("N\n");


    }
}