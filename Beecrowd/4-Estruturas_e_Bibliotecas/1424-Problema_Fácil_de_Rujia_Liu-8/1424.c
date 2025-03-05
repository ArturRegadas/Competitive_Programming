#include <stdio.h>
#include <stdlib.h>

#define MAX_KEYS 1000001  
#define MAX_N 100001  

typedef struct Occurrence{
    int *values;
    int size;
}Occurrence;

Occurrence occurrence[MAX_KEYS];

int main() {
    int size, cases, init, wanted, current;

    
    for (int i = 0; i < MAX_KEYS; i++) {
        occurrence[i].values = NULL;
        occurrence[i].size = 0;
    }

    while (scanf("%d %d", &size, &cases) == 2) {

        for (int i = 0; i < MAX_KEYS; i++) {
            free(occurrence[i].values);
            occurrence[i].values = NULL;
            occurrence[i].size = 0;
        }


        for (int i = 0; i < size; i++) {
            scanf("%d", &current);
            int index = occurrence[current].size;
            occurrence[current].size++;
            occurrence[current].values = realloc(occurrence[current].values, occurrence[current].size * sizeof(int));
            occurrence[current].values[index] = i + 1; 
        }


        for (int c = 0; c < cases; c++) {
            scanf("%d %d", &init, &wanted);
            if (wanted >= MAX_KEYS || init > occurrence[wanted].size)
                printf("0\n");
            else
                printf("%d\n", occurrence[wanted].values[init - 1]);
        }
    }

    for (int i = 0; i < MAX_KEYS; i++) {
        free(occurrence[i].values);
    }

    return 0;
}
