#include <stdio.h>

int main() {

    float a, a1, a2, b, b1, b2;
    scanf("%f", &a);
    scanf("%f", &a1);
    scanf("%f", &a2);
    scanf("%f", &b);
    scanf("%f", &b1);
    scanf("%f", &b2);

    
    printf("VALOR A PAGAR: R$ %.2f\n", a1*a2+b1*b2);
    return 0;
}