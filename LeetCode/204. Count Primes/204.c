#include <stdio.h>
#include <stdlib.h>

void RemoveMultiples(int* primes,int multple,int size){
    for(int i = multple*2; i < size; i+=multple ){
        primes[i] = 0;
    }
}

int countPrimes(int n) {
    int Resolve = 0;

    int *primes =(int*)malloc(n* sizeof(int));
    for (int i = 0; i < n; i++) {
        primes[i] = 1;
    }
    for(int i = 2; i<n; i++){
        if(primes[i]){
            Resolve+=1;
            RemoveMultiples(primes, i, n);
        }
    }

    return Resolve;
}
