#include <stdio.h>

int main() {
    int rook, size, x, ansI, current, ansV;
    int cases;
    char c;
    
    scanf("%d", &cases);
    for (int r = 0; r < cases; ++r) {
        scanf("%d%d", &rook, &size);
        int lake[size];
        for (int i = 0; i < size; i++) lake[i] = 0;

        for (int i = 0; i < rook; ++i) {
            scanf(" %c-%d", &c, &x);
            lake[x - 1] = (c == 'S') ? 1 : 2;
        }

        ansI = 0;
        current = 0;
        int skip = 0;

        for (int i = 0; i < size; ++i) {
            current++;
            if (current > ansI) ansI = current;

            if (lake[i] == 1) {
                if (!skip) {
                    lake[i] = 2;
                } else {
                    current = 0;
                }
                skip = !skip;
            } else if (lake[i] == 2) {
                current = 0;
            }
        }

        current = 0;
        ansV = 0;
        for (int i = 0; i < size; i++) {
            current++;
            if (current > ansV) ansV = current;
            if (lake[i] == 2) current = 0;
        }

        printf("Case %d: %d\n", r + 1, (ansI > ansV) ? ansI : ansV);
    }

    return 0;
}
