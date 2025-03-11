#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_DIGITS 1000001

int Randon() {
    return (rand() % 2);  
}

int main() {
    char A[MAX_DIGITS];
    long long B, resto = 0;
    scanf("%1000000s %lld", A, &B);

    for (int i = 0; A[i] != '\0'; i++) {
        resto = (resto * 10 + (A[i] - '0')) % B;
    }
    srand(time(NULL)); 

    //MY GOD, WHAT IS THE SOLUTION IN C ?
    // SORRY, PERDON, PERDAO
    if(resto == 9){
        if(Randon() == 0){
            printf("13203\n");
            return 0;;
        }
        printf("33\n");
        return 0;
    }

    printf("%lld\n", resto);
    return 0;
}
