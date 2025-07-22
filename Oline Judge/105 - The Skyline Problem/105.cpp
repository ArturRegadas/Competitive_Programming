#include <bits/stdc++.h>
#define INF (int)1e9
using namespace std;

bool cmp(vector<int> a, vector<int> b){
    if (a[0] != b[0]) return a[0] < b[0];

    if (a[2] != -1 && b[2] != -1)
        return a[1] > b[1]; 

    if (a[2] == -1 && b[2] == -1)
        return a[1] < b[1]; 

    return a[2] != -1;
}

int main(){
    //{}
    vector<vector<int>> city;
    int l, h, r;
    while(cin>>l>>h>>r){
        city.push_back({l, h, r});
        city.push_back({r, h, -1});
    }
    sort(city.begin(), city.end(), cmp);
    
    vector<int> ans; 
    // {height | end}
    priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
    int ant = 0;

    int dist, height, end, current;
    for(vector<int> i : city){
        dist = i[0];
        height = i[1];
        end = i[2];

        while(!pq.empty() && pq.top().second <= dist)
            pq.pop();
        
        if(end != -1){
            pq.push({height, end});
        }      
        if(pq.empty())
            current = 0;
        else
            current = pq.top().first;

        if(ant != current){
            ans.push_back(dist);
            ans.push_back(current);
            ant = current;   
        }
    }
    for(int i =0; i<ans.size()-1;i++)
        cout<<ans[i]<<" ";
    cout<<"0\n";


    return 0;
}