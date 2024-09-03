#include <stdio.h>
#include <math.h>
int main() {
    float x1, x2, y1, y2;
    scanf("%f", &x1);
    scanf("%f", &y1);
    scanf("%f", &x2);
    scanf("%f", &y2);
    printf("%.4f\n",pow(pow(x2-x1, 2)+pow(y2-y1, 2), 0.5));

    return 0;
}