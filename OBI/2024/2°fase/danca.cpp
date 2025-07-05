#include<bits/stdc++.h>
using namespace std;

int columns[1000010];

int main(){
    int n,m, p;
    scanf("%d%d%d",&n, &m, &p);
    for(int i = 0; i<m; i++)columns[i] = i;
    vector<vector<int>> matriz(n, vector<int>(m, 0));
    int c=1;
    for(int i = 0; i<n; i++){
        for(int j =0; j<m; j++){
            matriz[i][j] = c;
            c++;
        }
    }
    char cmd;
    int d1, p1;
    for(int i =0; i<p; i++){
        cin>> cmd>>d1>>p1;
        if(cmd == 'L')
            swap(matriz[d1-1], matriz[p1-1]);
        else    
            swap(columns[d1-1], columns [p1-1]);
    }
    
    
    for(int i =0; i<n; i++){
        for(int j =0; j<m-1; j++){
            printf("%d ", matriz[i][columns[j]]);
        }
        printf("%d\n", matriz[i][columns[m-1]]);
    }
    

    return 0;
}