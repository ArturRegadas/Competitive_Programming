#include <stdio.h>

int main() {
    // Write C code here
    double a, b;
    scanf("%lf", &a);
    scanf("%lf", &b);
    
    printf("MEDIA = %.5f\n", (a * 3.5 + b * 7.5)/11);

    return 0;
}