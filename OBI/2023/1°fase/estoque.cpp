#include <bits/stdc++.h>
using namespace std;

int matriz[510][510];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    int c;
    scanf("%d", &c);

    int y, x;
    int ans =0;
    for(int i =0; i<c;i++){
        scanf("%d%d", &y, &x);
        y--; x--;
        if (matriz[y][x] > 0 ){
            matriz[y][x]--;
            ans++;
        }
    }
    printf("%d\n", ans);

    return 0;
}