#include <stdio.h>


int main(){

    double radix, gas;
    
    scanf("%lf%lf", &radix, &gas);
    
    double area =  (4.0/3.0) * (3.1415*(radix*radix*radix));
    
    printf("%d\n",(int)(gas/area));
    
    return 0;
}