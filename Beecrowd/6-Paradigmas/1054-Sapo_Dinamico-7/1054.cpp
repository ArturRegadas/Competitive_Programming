#include <bits/stdc++.h>
#define MAXN 1000000018
using namespace std;

int main(){
    int rook, size, x, ansI, current, ansV;
    bool skip;
    char c;
    int cases;scanf("%d", &cases);
    for(int r =0;r<cases;++r){
        scanf("%d%d", &rook, &size);
        vector<int> lake(size);
        for(int i =0;i<rook;++i){
            scanf(" %c-%d", &c, &x);
            if(c=='S')lake[x-1]=1;
            else lake[x-1]=2;
        }
        ansI = 0;
        current =0;
        skip=false;
        
        for(int i =0; i<size;++i){
            current++;
            ansI=max(ansI, current);
            if(lake[i]==1){
                if(!skip){
                    lake[i] = 2;
                }
                else{
                    current=0;
                }
                skip = !skip;
            }
            else if(lake[i] == 2){current=0;}
        }

        current =0;
        ansV=0;
        for(int i = 0;i<size;i++){
            current ++;
            ansV = max(ansV, current);
            if(lake[i] == 2)current =0;
        }


        printf("Case %d: %d\n", r+1, max(ansI, ansV));
    }

    return 0;
}