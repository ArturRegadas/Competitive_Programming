#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int maior(double *nuns){
    double maior = INFINITY*-1;
    for(int i =0; i<3; i++){
        if (nuns[i]>maior){
            maior=nuns[i];
        }
    }
    return maior;
}

int main() {
    double a, b, c;
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);
    double *nuns=(double*)malloc(3*sizeof(double));
    nuns[0]=a;
    nuns[1]=b;
    nuns[2]=c;
    printf("%d eh o maior\n",maior(nuns));
    return 0;
}