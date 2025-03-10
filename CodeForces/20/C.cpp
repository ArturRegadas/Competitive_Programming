#include <bits/stdc++.h>
#define INF (long long)1e18+10
#define pb push_back
#define F first
#define S second
#define map unordered_map<long long, vector<pair<long long , long long>>>
using namespace std;

unordered_map<long long, long long> parents;

void getPath(long long current, vector<long long>& ans){
    if(current != parents[current]){
        getPath(parents[current], ans);
    }
    ans.pb(current);
}

void dijkstra(long long init, long long destiny, map graph){
    long long currPrice, currNode, iPrice, iNode;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> pq;
    unordered_map<long long, long long> prices;
    parents[init] = init;
    for(const auto& [key, value] : graph)prices[key] = INF;
    prices[init] = 0;
    pair<long long , long long> current;
    pq.push({0, init});
    while(!pq.empty()){
        current = pq.top();
        pq.pop();
        currPrice = current.F;
        currNode = current.S;
        if(currPrice > prices[currNode])continue;
        if(currNode == destiny){
            vector<long long> ans;
            getPath(destiny, ans);
            for(long long i =0;i<ans.size()-1;i++)printf("%lld ", ans[i]);
            printf("%lld\n", ans.back());
            return;

        }
        for(pair<long long, long long> i : graph[currNode]){
            iPrice = i.S;iNode = i.F;
            if(prices[currNode]+iPrice < prices[iNode]){
                parents[iNode] = currNode;
                prices[iNode] = prices[currNode]+iPrice;
                pq.push({prices[iNode], iNode});
            }
        }
    }
    printf("-1\n");    
}

int main(){
    long long vertices,edges, init = 1, destiny;
    long long in, d, p;
    scanf("%lld%lld", &vertices, &edges);
    destiny = vertices;

    map graph;
    for(long long i =0;i<edges;++i){
        scanf("%lld%lld%lld", &in, &d, &p);
        graph[in].pb({d, p});
        graph[d].pb({in, p});
    }
    //scanf("%d%d", &init, &destiny);
    dijkstra(init, destiny, graph);


    return 0;
}