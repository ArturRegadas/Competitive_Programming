#include <bits/stdc++.h>
using namespace std;
#define MAX 1001000



int main(){
    
    int r;scanf("%d",&r);
    int n, m;
    for(int i =0;i<r;i++){
        scanf("%d%d",&n,&m);
        vector<int> dp(m+1, MAX);
        dp[0]=0;
        int current;
        for(int i = 0;i<n;i++){
            scanf("%d", &current);
            for(int j = 0; j<m;j++){
                if(current<=j+1){
                    dp[j+1] = min(dp[j+1], dp[j-current+1]+1);
                }
            }
        }
        /*
        for(int j=0;j<=n;j++){
            for(int k=0;k<=m;k++){
                cout<<dp[j][k]<<" ";
            }
            cout<<"\n";
        }
        */
        printf("%d\n",dp[m]);
    }

    return 0;
}