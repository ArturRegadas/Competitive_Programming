#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s;
    int x, a6 = 0, a5 = 0, a4 = 0;

    for (int i = 0; i < 6; i++) {
        scanf("%d", &x);
        s.insert(x);
    }

    while (true) {
        vector<int> c(6);
        int ac = 0;

        for (int i = 0; i < 6; i++) {
            scanf("%d", &c[i]);
        }

        if (c[0] == 0 && c[1] == 0 && c[2] == 0 && c[3] == 0 && c[4] == 0 && c[5] == 0) break;

        for (int i = 0; i < 6; i++) {
            if (s.find(c[i]) != s.end()) ac++;
        }
        if (ac == 6)a6++;
        else if (ac == 5) a5++;
        else if (ac == 4) a4++;
    }

    printf("6 %d\n", a6);
    printf("5 %d\n", a5);
    printf("4 %d\n", a4);

    return 0;
}
