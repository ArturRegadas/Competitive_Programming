#include <bits/stdc++.h>
using namespace std;


int matriz[50][50];
int n, m;

int getNeighbors(int x, int y){
    int ans = 0;
    if(x+1 < m)
        if(matriz[y][x+1] == 1)
            ans++;

    if(x-1>=0)
        if(matriz[y][x-1] == 1)
            ans++;

    if(y+1 < n)
        if(matriz[y+1][x] == 1)
            ans++;

    if(y-1 >= 0)
        if(matriz[y-1][x] == 1)
            ans++;

    if(y+1 < n && x+1 < m)
        if(matriz[y+1][x+1] == 1)
            ans++;

    if(y+1 < n && x-1 >= 0)
        if(matriz[y+1][x-1] == 1)
            ans++;

    if(y-1 >= 0 && x+1 < m)
        if(matriz[y-1][x+1] == 1)
            ans++;

    if(y-1 >= 0 && x-1 >= 0)
        if(matriz[y-1][x-1] == 1)
            ans++;
    
    return ans;

}

int main(){
    scanf("%d%d", &n, &m);
    for(int i =0; i< n; i++){
        for(int j =0;j<m;j++)
            scanf("%d", &matriz[i][j]);
    }
    int count = 1;
    int minus = 99;
    int current;
    vector<int> list;
    for(int i =0; i<n;i++){
        for(int j = 0;j<m;j++){
            if(matriz[i][j] == 0){
                current = getNeighbors(j,i);
                if(current < minus){
                    minus = current;
                    list.clear();
                    list.push_back(count);
                }
                else if (current == minus)
                    list.push_back(count);
            }
            count++;
        }
    }
    printf("%d\n", minus);
    for(int i : list){
        printf("%d\n", i);
    }



    return 0;
}