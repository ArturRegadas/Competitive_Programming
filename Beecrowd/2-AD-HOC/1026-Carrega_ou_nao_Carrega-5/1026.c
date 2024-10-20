#include <stdio.h>
#include <math.h>

void bin(double n, double array[33]) {
    int indic=32;
    while (n > 0) {
        double resto = fmod(n, 2);
        n = floor(n/2);
        array[indic]=resto;
        indic--;
    }

}


int main() {
    while(1){
        double n1, n2, cv, resultado;
        resultado=0;
        if (scanf("%lf", &n1) == -1){
            break;
        }
        
        if (scanf("%lf", &n2) == -1){
            break;
        }
        
        double array1[33]={0};
        bin(n1, array1);
        double array2[33]={0};
        bin(n2, array2);
        for (int i =0; i<33; i++){
            cv=array1[i]+array2[i];
            if (cv ==2){
                cv=0;
            }
            resultado+=cv*pow(2, 33-(i+1));   
           
        }
         printf("%.0f\n", resultado);

        //10101010101010101010101010101010
        // 1010101010101010101010101010101
        
        }
    return 0;
}