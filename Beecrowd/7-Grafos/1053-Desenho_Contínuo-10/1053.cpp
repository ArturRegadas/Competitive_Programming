#include <bits/stdc++.h>
#define pb push_back
using namespace std;


struct point{
    int y;
    int x;
};

struct line{
    bool vertical;
    long double m;
    long double b;
};

point madePoint(int a, int b){
    point x;
    x.y=a;
    x.x=b;
    return x;
}

long double f(line a, int x){
    return a.m*x+a.b;

}

line madeLine(point a, point b){
    line x;
    x.m=(a.y-b.y)/(a.x-b.x);
    if(a.x == b.x)x.vertical = true;
    else x.vertical = false;
    x.b = a.y - x.m*a.x;
    return x;
}

string getMax(unordered_map<string, int>prices){
    string ans = "NULL";
    int maxPrice=-1;
    for(const auto& [current, price] : prices){
        if(price > maxPrice){
            maxPrice = price;
            ans = current;
        }
    }
    return ans;

}

long double calcPrice(
    unordered_map<string, unordered_map<string, long double>>graph,
    unordered_map<string, string>parent,
    string current
    ){
        long double ans = 0;
        set<string> processed;
        while(current!="NULL"){
            cout<<current<<"\n";
            processed.insert(current);
            ans += graph[current][parent[current]];
            current = parent[current];
        }
        for(const auto & [son, parentC] : parent){
            if(processed.find(son)== processed.end())ans+=graph[son][parentC]*2;
        }
        return ans;

}
void printVector(vector<string> p){
    for(string i : p)cout<<i<<" ";
    cout<<"\n";
}

long double minusPrice(unordered_map<string, unordered_map<string, long double>>graph, string init){
    unordered_map<string, string> parent={{init, "NULL"}};
    unordered_map<string, int> prices={{init,0}};
    vector<string> queue = {init};
    string current;
    set<string> inQueue = {init};
    set<string> processed;
    while(!queue.empty()){
        current = queue[0];queue.erase(queue.begin());inQueue.erase(current);
        for(const auto &[neighbor, cost] : graph[current]){
            if(processed.find(neighbor)==processed.end()  && inQueue.find(neighbor)==inQueue.end() && neighbor != current){
                queue.pb(neighbor);
                inQueue.insert(neighbor);
                prices[neighbor]=prices[current]+1;
                parent[neighbor] = current;
            }
        }
        processed.insert(current);
    }

    cout<<"f\n";
    if(processed.size()<graph.size())return -1;
    return calcPrice(graph, parent, getMax(prices) );
}
void printGraph(unordered_map<string, unordered_map<string, long double>> mapa){
    for (const auto& [chave, submapa] : mapa) {
        std::cout << chave << ":\n";
        for (const auto& [subchave, valor] : submapa) {
            std::cout << "  " << subchave << ": " << valor << "\n";
        }
    }

}

long double calcDistance(string a, string b){
    long double c1 = abs((a[0]-65) - (b[0]-65))*abs((a[0]-65) - (b[0]-65));
    long double c2 = abs((a[1]-'0') - (b[1]-'0'))*abs((a[1]-'0') - (b[1]-'0'));
    return sqrt(c1+c2);
}

bool inFront(){

}

int main(){
    string p, d;
    long double distance;
    int repeat, cases;scanf("%d", &cases);
    for(int r =0;r<cases;r++){
        scanf("%d", &repeat);
        unordered_map<string, unordered_map<string, long double>> graph;
        set<string> ordem;
        for(int i =0;i<repeat;i++){
            cin>>p>>d;
            distance = calcDistance(p, d);

            // passar na mesma linha vai adicionar ao menor ponto e menor ponto ao ponto
            // ---*-----*______*
            //----*_____*______*
            if(inFront()){

            }
            graph[p][d]= distance;
            graph[d][p]=distance;
            ordem.insert(p);
            ordem.insert(d);
        }

        printGraph(graph);
        printf("Case %d: ", r+1);
        long double ans =999999999999999;
        for(string i : ordem){
            ans = min(ans, minusPrice(graph, i));
        }
        if(ans==-1)printf("~x(\n");
        else printf("%2Lf\n", ans);
    }
    return 0;
}