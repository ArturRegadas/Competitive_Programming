#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> m(260, vector<int>(260, 1));
int lp, cp, l, c;

int resp(string cmd) {
    int ans = 0;
    for (char co : cmd) {
        int nl = lp, nc = cp;

        if (co == 'N') nl--;
        else if (co == 'S') nl++;
        else if (co == 'O') nc--;
        else if (co == 'L') nc++;

        
        if(!(nl < 0 || nl >= l || nc < 0 || nc >= c)){
            if (m[nl][nc] == 2) {
                ans = 0;
            }
            else if(m[nl][nc] == 1){
                ans++;
                m[nl][nc] = 0;
            }
            lp = nl;
            cp = nc;
        }
        
        
    }
    return ans;
}

int main() {
    int nf, lf, cf;
    scanf("%d %d", &l, &c);
    scanf("%d", &nf);

    for (int i = 0; i < nf; i++) {
        scanf("%d %d", &lf, &cf);
        m[lf - 1][cf - 1] = 2;
    }

    scanf("%d %d", &lp, &cp);
    lp--;
    cp--;
    m[lp][cp] = 0;
    string cmd;
    cin >> cmd;

    printf("%d\n", resp(cmd));

    return 0;
}
