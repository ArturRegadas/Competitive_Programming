#include <stdio.h>
#include <stdbool.h>

#define MAX_PLACA 9000  
#define MAX_ESTACIONAMENTO 1000

int main() {
    int size, cases, placa, sizeCar, faturamento;
    char command;

    while (scanf("%d %d", &size, &cases) != EOF) {
        int estacionamento[MAX_ESTACIONAMENTO] = {0};  
        int position[MAX_PLACA] = {-1};  
        faturamento = 0;

        for (int r = 0; r < cases; r++) {
            scanf(" %c", &command);
            if (command == 'C') {  
                scanf("%d %d", &placa, &sizeCar);
                bool estacionado = false;

                for (int i = 0; i <= size - sizeCar; i++) {
                    if (estacionamento[i] == 0) {  
                        bool podeEstacionar = true;
                        for (int j = i; j < i + sizeCar; j++) {
                            if (estacionamento[j] > 0) {  
                                podeEstacionar = false;
                                break;
                            }
                        }

                        if (podeEstacionar) {
                            for (int j = i; j < i + sizeCar; j++) {
                                estacionamento[j] = placa;  
                            }
                            position[placa - 1000] = i;  
                            faturamento += 10;
                            estacionado = true;
                            break;
                        }
                    }
                }
            } 
            else if (command == 'S') {  
                scanf("%d", &placa);
                int idx = position[placa - 1000];

                if (idx != -1) {  
                    for (int j = idx; j < size && estacionamento[j] == placa; j++) {
                        estacionamento[j] = 0;  
                    }
                    position[placa - 1000] = -1;  
                }
            }
        }

        printf("%d\n", faturamento);
    }

    return 0;
}
