#include <stdio.h>

int main() {
    int repeat;
    int xlog, ylog;
    int xcurrent, ycurrent;

    while (1) {
        scanf("%d", &repeat);
        if (!repeat) break;

        scanf("%d %d", &xlog, &ylog);

        for (int i = 0; i < repeat; i++) {
            scanf("%d %d", &xcurrent, &ycurrent);

            if (xcurrent == xlog || ycurrent == ylog) printf("divisa\n");
            else if (xcurrent > xlog && ycurrent > ylog) printf("NE\n");
            else if (xcurrent < xlog && ycurrent > ylog) printf("NO\n");
            else if (xcurrent < xlog && ycurrent < ylog) printf("SO\n");
            else printf("SE\n");
        }
    }

    return 0;
}
