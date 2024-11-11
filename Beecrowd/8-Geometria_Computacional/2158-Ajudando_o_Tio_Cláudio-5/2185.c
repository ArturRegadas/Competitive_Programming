#include <stdio.h>

int main(){
    long long fp, fh;
    long long vertex, edge;
    int i =1;
    while(scanf("%lld%lld", &fp, &fh)!=EOF){

            
            edge = (fp*5+fh*6)/2;
            vertex = 2-(fp+fh)+edge;
            printf("Molecula #%d.:.\n", i);
            printf("Possui %lld atomos e %lld ligacoes\n\n", vertex, edge);
            i++;

    }

    return 0;
}