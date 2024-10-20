#include <stdio.h>

int josephus(int n, int k) {
    int posicaoSegura = 0;  

    for (int i = 2; i <= n; i++) {
        posicaoSegura = (posicaoSegura + k) % i;
    }

    return posicaoSegura;
}

int main() {
    
    int repeat;
    scanf("%d", &repeat);
    for(int i=0; i<repeat; i++){
        
        int n ; 
        int k ; 
        scanf("%d", &n);
        scanf("%d", &k);
    
        int resultado = josephus(n, k);
        printf("Case %d: %d\n",i+1 ,resultado + 1);
    }
    return 0;
}
