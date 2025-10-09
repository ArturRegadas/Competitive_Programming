#include <bits/stdc++.h>
#define umap unordered_map
using namespace std;


int main(){
    int n, t;
    scanf("%d", &n);
    // {valor, tipo}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    //
    umap<int, priority_queue<int, vector<int>, greater<>>> typesObjs;
    vector<pair<int, int>> objs(n);

    for(int i = 0; i<n; i++){
        pair<int, int> aux;
        scanf("%d", &objs[i].second);
    }
    for(int i = 0; i<n; i++){
        scanf("%d", &objs[i].first);
    }

    for(pair<int, int> i : objs){
        pq.push({i.first, i.second});
        typesObjs[i.second].push(i.first);
    }
    objs.clear();

    // armazena tipos que devem ser excluidos
    vector<int> queue(100010, 0);
    int c, type;
    scanf("%d", &c);
    long long ans = 0;
    for(int i =0; i<c; i++){
        scanf("%d", &type);
        while(queue[pq.top().second] > 0){
            queue[pq.top().second] --;
            pq.pop();
        }
        if(type == 0 && !pq.empty()){
            pair<int, int> minus = pq.top();
            pq.pop();
            typesObjs[minus.second].pop();
            ans+=(long long)minus.first;
        }
        else if(!typesObjs[type].empty()){
            int minusN = typesObjs[type].top();
            typesObjs[type].pop();
            queue[type] ++;
            ans += (long long) minusN;
        }

    }
    printf("%lld\n", ans);
}