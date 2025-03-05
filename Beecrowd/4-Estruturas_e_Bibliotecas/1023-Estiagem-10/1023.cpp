#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases, size, water;
    while(1){
        scanf("%d", &cases);
        if(cases==0)return 0;
        vector<pair<int, int>> city(cases);
        for(int i=0;i<cases;i++){
            scanf("%d%d", &size, &water);
            city[i] ={water/size, size};
        }
        sort(city.begin(), city.end());
        printf("Cidade# %d:\n");
        for(int i =0;i<size-1;i++)printf("%d-%d ", city[i].second, city[i].first);
        printf("%d-%d\n", city.back().second, city.back().first);
        
    }
}