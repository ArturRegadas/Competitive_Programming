//passa ate o 4 caso, implementar LCA para ACCEPT
#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<pair<int, int>, int>a, pair<pair<int, int>, int>b){
    return a.second > b.second;
}

class UnF{
public:
    unordered_map<int, int> parent;
    unordered_map<int, int> size;
    UnF(int n) {
        for(int i =0; i<n;i++){
            parent[i+1] = i+1;
            size[i+1] = 1;
        }

    }
    bool Union(int a, int b){
        int pa = Find(a);
        int pb = Find(b);
        if(pa == pb)
            return false;
        if(size[pa]<size[pb]){
            parent[pa] = pb;
            size[pa]+=size[pb];
        }
        else{
            parent[pb] = pa;
            size[pb]+=size[pa];
        }
        return true;

    }
    int Find(int a){
        if(a == parent[a])
            return a;
        return Find(parent[a]);
    }
};

unordered_map<int, unordered_map<int, int>> kruskal(vector<pair<pair<int, int>, int>> ordened, int n){
    unordered_map<int, unordered_map<int, int>> ans;
    UnF unionFind(n);
    for(pair<pair<int, int>, int> i : ordened){
        pair<int, int> edges = i.first;
        if(unionFind.Union(edges.first, edges.second)){
            ans[edges.first][edges.second] = i.second;
            ans[edges.second][edges.first] = i.second;
        }
    }
    return ans;

}

int dfs(unordered_map<int, unordered_map<int, int>> graph, int a, int b) {
    vector<int> stack = {a};
    unordered_map<int, int> price;
    price[a] = 9999999;
    unordered_set<int> visited;

    while (!stack.empty()) {
        int current = stack.back();
        stack.pop_back();

        if (current == b)
            return price[b]; 

        if (visited.count(current))
            continue;
        visited.insert(current);

        for (const auto& neighbor : graph[current]) {
            int next = neighbor.first;  
            if (!visited.count(next)) {
                price[next]=min(price[current], neighbor.second);
                stack.push_back(next);
            }
        }
    }
}

int main(){
    int n, b;
    scanf("%d%d", &n, &b);
    vector<pair<pair<int, int>, int>> edges(b);
    for(int i =0; i<b;i++)
        scanf("%d%d%d", &edges[i].first.first, &edges[i].first.second, &edges[i].second);
    
    sort(edges.begin(), edges.end(), cmp);

    unordered_map<int, unordered_map<int, int>> mst= kruskal(edges, n);
    
    //implementar LCA

    int p, d, f;
    scanf("%d", &p);
    for(int i =0; i<p; i++){
        scanf("%d%d", &d, &f);
        printf("%d\n", dfs(mst, d, f));
        
    }

    
    
}