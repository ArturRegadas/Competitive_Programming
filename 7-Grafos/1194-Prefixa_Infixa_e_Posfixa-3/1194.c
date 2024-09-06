#include <stdio.h>

int p_i(char infixa[],  char proc, int size){

    for(int i=0; i<size, i++){
        if(infixa[i]==proc){
            return i-1;
        }
    }
    return -1;


}

int main(){
    int repeat, size;

    char prefixa[53],infixa[53], raiz, result[53];

    scanf("%d", &repeat);

    int qtd, nad, qtd2, c, passed, passed2;

    for(int r=0; r<repeat; r++){
        scanf("%d", &size);
        scanf("%s", prefixa);
        scanf("%s", infixa);

        raiz=prefixa[0];

        qtd=size;
        nad=0;

        qtd2=p_i(infixa, raiz, qtd);

        c=0;
        passed2=1;
        passed=1;

        for(int i=0; i<size; i++){
            if(nad==1){
                break;
            }
            else if()
        }
        







    }

}