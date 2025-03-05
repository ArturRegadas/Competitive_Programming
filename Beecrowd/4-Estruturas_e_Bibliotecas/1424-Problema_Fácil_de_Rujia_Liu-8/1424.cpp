#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main(){
    int init, wanted, current;
    int size, cases;
    while(scanf("%d%d", &size, &cases) == 2){
        unordered_map<int, vector<int>> occurrence;
        for(int i =0;i<size;i++){
            scanf("%d", &current);
            occurrence[current].pb(i+1);
        }
        for(int c = 0; c<cases;c++){
            scanf("%d%d", &init, &wanted);
            if(occurrence[wanted].size() < init)printf("0\n");
            else printf("%d\n", occurrence[wanted][init-1]);
        }
    }
    return 0;
}