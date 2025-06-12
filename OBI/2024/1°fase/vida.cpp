#include <cstdio>
#include <iostream>

using namespace std;


int calcNeighbor(char matriz[110][110], int i, int j){
    int ans = 0;
    if(matriz[i+1][j] == '1') ans++;
    if(matriz[i-1][j] == '1') ans++;
    if(matriz[i][j+1] == '1') ans++;
    if(matriz[i][j-1] == '1') ans++;
    if(matriz[i+1][j-1] == '1') ans++;
    if(matriz[i-1][j+1] == '1') ans++;
    if(matriz[i+1][j+1] == '1') ans++;
    if(matriz[i-1][j-1] == '1') ans++;
    return ans;

}

int main(){
    int n, q, v;
    char matriz[110][110];
    char nmatriz[110][110];
    scanf("%d%d", &n, &q);
    for(int i = 1; i<=n; i++){
        scanf(" %s", &nmatriz[i][1]);
    }
    for(int k = 0; k<q;k++){
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                v = calcNeighbor(nmatriz,i, j);
                if (nmatriz[i][j] == '1'){
                    matriz[i][j] = '0';
                    if(v == 3 || v == 2)
                        matriz[i][j] = '1';
                }
                else{
                    matriz[i][j] = '0';
                    if (v == 3){
                        matriz[i][j] = '1';
                    }
                }
            }
        }
        for(int i = 1; i<=n;i++){
            for(int j = 1; j<=n; j++)
                nmatriz[i][j] = matriz[i][j];
        }
    }
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n ;j++){
            cout<<matriz[i][j];
        }
        cout<<"\n";
    }

    return 0;
}