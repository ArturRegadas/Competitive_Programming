#include<bits/stdc++.h>
using namespace std;
int main(){;
    int s, t;
    scanf("%d%d", &s, &t);
    vector<set<int>> graph(s);
    int d, p;
    for(int i =0; i<t; i++){
        scanf("%d%d", &d, &p);
        graph[d-1].insert(p-1);
        graph[p-1].insert(d-1);
    }
    int c, sc;
    scanf("%d", &c);
    int r =0;
    for(int i = 0; i<c; i++){
        scanf("%d", &sc);
        vector<int> perc(sc);
        for(int j =0; j<sc; j++)
            scanf("%d", &perc[j]);
        bool ans = true;
        for(int j =0; j<sc-1; j++){
            if(graph[perc[j]-1].find(perc[j+1]-1) == graph[perc[j]-1].end()){
                ans = false;
                break;
            }
        }
        if(ans)
            r++;

    }
    printf("%d\n", r);
}