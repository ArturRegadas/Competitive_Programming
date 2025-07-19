//solucao com kruskal, LCA e DP
//I M THE BEST, THE LEGEND OF WORLD
#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#define FIND(c, k) ((c).find(k)!=(c).end())
#define uset unordered_set
#define umap unordered_map
#define INF (int)1e9
#define MAXN (int)1e5+10
#define MAXLOG 20
using namespace std;

bool cmp(pair<pair<int, int>, int>a, pair<pair<int, int>, int>b){
    return a.second > b.second;
}

class UnF{
public:
    umap<int, int> parent;
    umap<int, int> size;
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
    int Find(int a) {
        if (a != parent[a])
            parent[a] = Find(parent[a]);
        return parent[a];
    }
};

umap<int, umap<int, int>> kruskal(vector<pair<pair<int, int>, int>> ordened, int n){
    umap<int, umap<int, int>> ans;
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

umap<int, umap<int, int>> mst;
vector<vector<int>> parent(MAXN, vector<int>(MAXLOG, -1));
vector<vector<int>> price(MAXN, vector<int>(MAXLOG, INF));
int depth [MAXN];
//current | parent
void dfs(int c, int p, int w){
    parent[c][0] = p;
    price[c][0] = w;
    for(int i =1; i<MAXLOG; i++)
        if(parent[c][i-1] != -1){
            parent[c][i] = parent[parent[c][i-1]][i-1];
            price[c][i] = min(
                //
                price[parent[c][i-1]][i-1],
                price[c][i-1]
            );
        }
        else{
            parent[c][i]  = -1;
            price[c][i] = INF;
        }


    for(const auto& [key, weight] : mst[c]){
        if(key != p && depth[key] == 0){
            depth[key] = depth[c] + 1;
            dfs(key, c, weight);
        }
    }
}

void printumap(umap<int, umap<int, int>> g){
    for(auto[key, value] : g){
        cout<<key<<" :\n";
        for(auto[key2, value2] : value){
            cout<<key2<<" - "<<value2<<"\n";
        }
        cout<<"\n";
    }
}
//lift normaliza a profundidade 
pair<int ,int> lift(int a, int k){
    int ans = INF;
    int i = 0;
    while(a != -1 && k >0){
        // o k vai descendo logariticamente e o a vai subindo exponencialmente  
        if(k%2==1){
            ans = min(ans, price[a][i]);
            a = parent[a][i];
        }
        k /= 2;
        i++;
    }
    return {a, ans};
}

int LCA(int a, int b){
    if(depth[b] > depth[a])
        swap(a, b);
        
        
    pair<int, int> data = lift(a, depth[a] - depth[b]);
    a = data.first;
    int ans = data.second;

    if (a == b)
        return ans;
    
    for(int i = MAXLOG - 1; i>=0; i--){
        //APENAS ACREDITE: seguindo essa logica qualquer soma pode ser obtida se tiver todos os numeros potencias de 2
        //parent funciona como um grafo
        if(parent[a][i] != -1 && parent[a][i] != parent[b][i] ){
            ans = min(ans, min(price[a][i], price[b][i]));
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return min(ans, min(price[a][0], price[b][0]));
}

void printM(vector<vector<int>> m, int n, int b){
    n++;
    for(int i =0; i<n; i++){
        for(int j =0; j<b; j++){
            if(m[i][j] == INF)
                cout<<"-1 ";
            else
                cout<<m[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    int n, b;
    scanf("%d%d", &n, &b);
    vector<pair<pair<int, int>, int>> edges(b);
    for(int i =0; i<b;i++)
        scanf("%d%d%d", &edges[i].first.first, &edges[i].first.second, &edges[i].second);
    
    sort(edges.begin(), edges.end(), cmp);

    mst = kruskal(edges, n);
    
    depth[1] = 1;
    dfs(1, -1, INF);
    
    int p, d, f;
    scanf("%d", &p);
    for(int i =0; i<p; i++){
        scanf("%d%d", &d, &f);
        printf("%d\n", LCA(d, f));
    }
    /*
    printM(parent,n,MAXLOG);
    cout<<"\n\n";
    printM(price,n,MAXLOG);
    */
    
}