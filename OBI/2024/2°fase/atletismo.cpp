#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> players(n);
    for(int i =0; i<n; i++){
        scanf("%d", &players[i].first);
        players[i].second = i;
    }
    sort(players.begin(), players.end());
    for(pair<int, int> i : players){
        printf("%d\n", i.second+1);
    }

    return 0;
}