#include <bits/stdc++.h>
using namespace std;

int graph[2020][2020];
int inverseGraph[2020][2020];
int visited[2020];
int inversionVisited[2020];
int version = 0;

void dfs(int current, int version, int vert){
    for(int i =0;i<vert;i++){
        if(graph[current][i]==version && visited[i]!=version){
            visited[i] = version;
            dfs(i, version, vert);
        }
    }
}
void Idfs(int current, int version, int vert){
    for(int i =0;i<vert;i++){
        if(inverseGraph[current][i]==version && inversionVisited[i]!=version){
            inversionVisited[i] = version;
            Idfs(i, version, vert);
        }
    }
}

int main(){
    int vertices, edges;
    int d, p, duo;
    while(1){
        
        scanf("%d%d", &vertices, &edges);
        if(vertices == 0 && edges == 0)return 0;
        version++;
        for(int i =0;i<edges;i++){
            scanf("%d%d%d", &d, &p, &duo);
            inverseGraph[p-1][d-1]=version;
            graph[d-1][p-1] = version;
            if(duo==2){
                graph[p-1][d-1] = version;
                inverseGraph[d-1][p-1] = version;
            }
        }
        dfs(0, version, vertices);
        Idfs(0, version, vertices);
        int ans = 1;
        for(int i =0;i<vertices;i++){
            if(visited[i]!=version || inversionVisited[i]!=version){
                ans = 0;
                break;
            }
        }
        printf("%d\n", ans);
        
    }
    return 0;
}