#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    vector<int> dp = {a};
    int i =0;
    while(a < c){
        dp.push_back(dp[i] * b);
        i++;
        a += dp[i];
    }
    printf("%d\n", i);
    
    return 0;
}