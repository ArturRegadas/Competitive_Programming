#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int l, c, n;
    scanf("%d%d%d", &l, &c, &n);

    // bitmap representando plano de calor (diferença 2D)
    vector<vector<int>> diff(l+2, vector<int>(c+2, 0));

    int cx, cy, cr, cb;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &cx, &cy, &cr, &cb);

        int r2 = cr * cr;

        //limitar para nao ultrapassar limite do plano
        int minX = max(1, cx - cr);
        int maxX = min(c, cx + cr);

        for (int xi = minX; xi <= maxX; xi++) {
            int dx = xi - cx;
            int dy2 = r2 - dx * dx;
            if (dy2 < 0) continue; // fora da circunferência

            int dy = (int)sqrt(dy2);
            int minY = max(1, cy - dy);
            int maxY = min(l, cy + dy);

            /*
            Em vez de incrementar ponto por ponto entre minY e maxY,
            aplicamos diferença acumulada vertical para cada coluna xi.
            diff[y][x] += cb
            diff[y+1][x] -= cb
            */

            diff[minY][xi] += cb;
            diff[maxY + 1][xi] -= cb;
        }
    }

    // Agora computamos o plano final com prefixo vertical
    int maxBit = 0, qtdBit = 0;
    vector<vector<int>> bitmap(l + 2, vector<int>(c + 2, 0));

    for (int x = 1; x <= c; x++) {
        int soma = 0;
        for (int y = 1; y <= l; y++) {
            soma += diff[y][x];
            bitmap[y][x] = soma;

            if (bitmap[y][x] > maxBit) {
                maxBit = bitmap[y][x];
                qtdBit = 1;
            } else if (bitmap[y][x] == maxBit) {
                qtdBit++;
            }
        }
    }

    printf("%d\n%d\n", maxBit, qtdBit);
    return 0;
}
