#include <stdio.h>
#include <string.h>
int p_i(char infixa[], char proc, int size) {
    for (int i = 0; i < size; i++) {
        if (infixa[i] == proc) {
            return i - 1;
        }
    }
    return -1;
}

int main() {
    int repeat;
    scanf("%d", &repeat);

    for (int r = 0; r < repeat; r++) {
        int qtd;
        char prefixa[510], infixa[510];
        scanf("%d %s %s", &qtd, prefixa, infixa);

        char raiz = prefixa[0];
        char result[510] = "";
        
        int qtd2 = p_i(infixa, prefixa[0], qtd);

        int s;
        if(qtd2==0){
            s=0;
        }
        else{
            s=1;
        }

        int c = 0;
        int passed = 1;
        int passed2 = 1;
        int nad = 0;


        for (int i = 0; i < qtd; i++) {
            if (nad) {
                if (passed) {
                    c++;
                    passed = 0;
                } else {
                    qtd--;
                    passed = 1;
                    c++;
                }
            } else if (infixa[c] == raiz) {
                nad = 1;
                c++;
            } else {
                if (passed2) {
                    strncat(result, &infixa[c], 1); 
                    passed2 = 0;
                    c++;
                } else {
                    if (infixa[qtd2 - 1] == infixa[c]) {
                        strncat(result, &infixa[qtd2], 1);
                        strncat(result, &infixa[qtd2 - 1], 1);
                        break;
                    } else {
                        strncat(result, &infixa[qtd2], 1);
                    }
                    passed2 = 1;
                    c++;
                }
            }
        }

        passed = 1;
        qtd = strlen(infixa);
        nad = 0;
        c = 0;

        for (int i = 0; i < qtd+s; i++) {
            if (nad) {
                if (passed) {
                    strncat(result, &infixa[c], 1);
                    c++;
                    passed = 0;
                } else {
                    strncat(result, &infixa[qtd - 1], 1);
                    qtd--;
                    passed = 1;
                }
            } else if (infixa[c] == raiz) {
                nad = 1;
                c++;
            } else {
                c++;
            }
        }
        strncat(result, &raiz, 1);
        printf("%s\n", result);
    }

    return 0;
}
