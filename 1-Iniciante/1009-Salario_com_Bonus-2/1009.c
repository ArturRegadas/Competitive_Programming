#include <stdio.h>

int main() {
    // Write C code here
    char a;
    scanf("%s", &a);
    double n1, n2;
    scanf("%lf", &n1);
    scanf("%lf", &n2);
    printf("TOTAL = R$ %.2f\n",n1+n2*(15.00 / 100.00));

    return 0;
}