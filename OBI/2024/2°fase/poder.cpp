#include <bits/stdc++.h>
using namespace std;
//subtarefa 4 53pts n = 1
long long n, m;

vector<pair<long long, long long>> getNeighbors(pair<long long, long long> current){
    long long y=current.first;
    long long x = current.second;
    vector<pair<long long, long long>> ans;
    if(x+1 < m){
        ans.push_back({y, x+1});
    }
    if(x-1 >= 0){
        ans.push_back({y, x-1});
    }
    
    if(y+1 < n){
        ans.push_back({y+1, x});
    }
    if(y-1>=0){
        ans.push_back({y-1, x});
    }

    return ans;
}

pair<set<pair<long long, long long>>, long long> busca(
    pair<long long, long long>init,
    vector<vector<long long>> matriz
){
    //{preco, {y, x}}
    priority_queue<
        pair<long long, pair<long long, long long>>, 
        vector<pair<long long, pair<long long, long long>>>, 
        greater<pair<long long, pair<long long, long long>>>
        > pq;

    long long x, y;
    long long val = 0;
    x = init.second;
    y = init.first;
    pq.push({matriz[y][x], {y, x}});
    set<pair<long long, long long>> processed;
    processed.insert({y, x});
    while(pq.size()>0){
        pair<long long, pair<long long, long long>> current = pq.top();pq.pop();
        if(val < current.first && val != 0){
            return {processed, val};
        }
        val+=current.first;
        vector<pair<long long, long long>> neighbors = getNeighbors(current.second);
        for(pair<long long, long long> i : neighbors){
            // se nao tiver em processed
            if(processed.find(i) == processed.end()){
                pq.push({matriz[i.first][i.second], {i.first, i.second}});
                processed.insert({i.first, i.second});
            }
        }
    }
    return {processed, val};
}

int main(){
    scanf("%lld%lld", &n, &m);
    vector<vector<long long>> matriz(n, vector<long long>(m));
    vector<vector<long long>> ans(n, vector<long long>(m, -1));
    for(long long i=0; i<n; i++){
        for(long long j=0; j<m; j++){
            scanf("%lld", &matriz[i][j]);
        }
    }

    for(long long i =0;i<n; i++){
        for(long long j =0; j<m;j++){
            if(ans[i][j] == -1){
                pair<set<pair<long long, long long>>, long long>pr = busca({i, j},matriz);
                ans[i][j] = pr.second;
                /*
                for(pair<long long, long long> current : pr.first){
                    ans[current.first][current.second] = pr.second;
                }
                */
            }
        }
    }
    for(long long i =0; i<n; i++){
        for(long long j = 0; j< m-1; j++){
            printf("%lld ", ans[i][j]);
        }
        printf("%lld\n", ans[i][m-1]);
    }

    return 0;
}