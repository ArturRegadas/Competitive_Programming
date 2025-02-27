#include <stdio.h>
#include <math.h>
#define k 1.06739568171118186925926376267113212L
int main() {
    long double s;

    while (scanf("%Lf", &s) == 1) {
        printf("%.10Lf\n", s * k);
    }

    return 0;
}
