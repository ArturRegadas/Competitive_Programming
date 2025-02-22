#include <bits/stdc++.h>
#define pb push_back
using namespace std;


long double minusPrice(unordered_map<string, vector<pair<string, long double>>>graph, string init){
    unordered_map<string, string> parent;
    vector<string> queue = {init};
    string current;
    while(queue.size()>0){
        current = queue[0];queue.erase(queue.begin());
        for(pair<string, long double> neighbor : graph[current]){
            
        }
    }
}


long double calcDistance(string a, string b){
    return sqrt(abs(((int)a[0]-65)-((int)b[0]-65)) * abs((int)a[1]-(int)b[1]));
}

int main(){
    string p, d;
    long double distance;
    int repeat, cases;scanf("%d", &cases);
    for(int r =0;r<cases;r++){
        scanf("%d", &repeat);
        unordered_map<string, vector<pair<string, long double>>> graph;
        set<string> ordem;
        for(int i =0;i<repeat;i++){
            cin>>p,d;
            distance = calcDistance(p, d);
            graph[p].pb({d, distance});
            graph[d].pb({p, distance});
            ordem.insert(p);
            ordem.insert(d);
        }

        long double ans =-1;
        for(string i : ordem){
            ans = max(ans, minusPrice(graph, i));
        }
    }
    return 0;
}