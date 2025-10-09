#include <bits/stdc++.h>
#define MAXN 2510
using namespace std;

class UnionFind{
    public:
    vector<int> parent;
    vector<int> size;

    UnionFind(int n) : parent(n), size(n, 1){
        for(int i = 0; i<n; i++)
            parent[i] = i;
    }

    int Find(int n){
        if(n == parent[n])
            return n;
        return Find(parent[n]);
    }


    bool Union(int a, int b){
        int parent_a = Find(a);
        int parent_b = Find(b);

        if(parent_a == parent_b)
            return false;

        if(size[parent_a] < size[parent_b])
            swap(parent_a, parent_b);
        
        parent[parent_b] = parent_a;
        size[parent_a] += size[parent_b];
        return true;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    UnionFind union_find(n);
    string g;
    for(int i = 0; i<n; i++){
        cin>>g;
        for(int j = 0; j<n; j++){
            if(g[j] == '1')
                union_find.Union(i, j);
        }
    }

    int c;
    cin>>c;
    for(int _ = 0; _<c; _++){
        int s;
        cin>>s;
        vector<int> query(s);
        for(int i =0; i<s; i++)
        cin>>query[i];
        
        bool ans = false;
        unordered_set<int> reps;
        for (int i = 0; i < s; i++) {
            int rep = union_find.Find(query[i] - 1);
            if (reps.find(rep) != reps.end()) {
                ans = true;
                break;
            }
            reps.insert(rep);
        }
        if(ans)
        cout<<"S\n";
        else
        cout<<"N\n";
    }


    return 0;
}