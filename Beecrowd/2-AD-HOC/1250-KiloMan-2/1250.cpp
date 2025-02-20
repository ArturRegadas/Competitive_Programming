#include <bits/stdc++.h>
using namespace std;

int main(){
    int repeat;scanf("%d", &repeat);
    int ans, size;
    string jumps;
    for(int r =0;r<repeat;r++){
        ans=0;
        scanf("%d", &size);
        vector<int> disparos(size);
        for(int i =0;i<size;i++)scanf("%d", &disparos[i]);
        cin>>jumps;
        for(int i =0;i<size;i++){
            if(jumps[i] == 'S' && disparos[i]<=2)ans++;
            else if(jumps[i] == 'J' && disparos[i]>2)ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}