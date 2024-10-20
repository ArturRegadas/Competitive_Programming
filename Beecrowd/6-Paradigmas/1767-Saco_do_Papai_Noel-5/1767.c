#include <stdio.h>

int minkg(int maxinum[], int maxp, int size) {
    int l = size;
    while (maxinum[l] == maxp) {
        l--;
    }
    return l + 1;
}

int maxprice(int price[], int weight[], int size, int repeat, int *maxitens_out, int *toyskg_out) {
    int maxinum[size + 1];
    int maxitens[size + 1];
    
    for (int i = 0; i <= size; i++) {
        maxinum[i] = 0;
        maxitens[i] = 0;
    }

    for (int i = 0; i < repeat; i++) {
        int value_p = price[i];
        int value_w = weight[i];

        for (int w = size; w >= value_w; w--) {
            if (maxinum[w - value_w] + value_p > maxinum[w]) {
                maxinum[w] = maxinum[w - value_w] + value_p;
                maxitens[w] = maxitens[w - value_w] + 1;
            }
        }
    }

    *toyskg_out = minkg(maxinum, maxinum[size], size);
    *maxitens_out = maxitens[size];

    return maxinum[size];
}

int main() {
    int r;
    scanf("%d", &r);

    for (int x = 0; x < r; x++) {
        int repeat;
        scanf("%d", &repeat);

        int prices[repeat];
        int weights[repeat];

        for (int i = 0; i < repeat; i++) {
            scanf("%d %d", &prices[i], &weights[i]);
        }

        int maxitens, toyskg;
        int ma = maxprice(prices, weights, 50, repeat, &maxitens, &toyskg);

        printf("%d brinquedos\n", ma);
        printf("Peso: %d kg\n", toyskg);
        printf("sobra(m) %d pacote(s)\n\n", repeat - maxitens);
    }

    return 0;
}
