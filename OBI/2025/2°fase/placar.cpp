#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    //    <momento do gol e quem fez>
    vector<pair<int, bool>> gols;

    scanf("%d", &n);
    int v;
    for(int i =0; i<n;i++){
        scanf("%d", &v);
        gols.push_back({v, true});
    }

    scanf("%d", &m);
    for(int i =0; i<m;i++){
        scanf("%d", &v);
        gols.push_back({v, false});
    }
    sort(gols.begin(), gols.end());
    int p1 = 0, p2 = 0;
    printf("0 0\n");
    for(pair<int, bool> i : gols){
        if(i.second)
            p1++;
        else
            p2++;
        printf("%d %d\n", p1, p2);
    }



    return 0;
}