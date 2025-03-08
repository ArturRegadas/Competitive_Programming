#include <bits/stdc++.h>
using namespace std;



int getMin(int a, int b){
    if(a == -1)return b;
    if(b == -1)return a;
    if(a<b)return a;
    return b;
}
//esvaziar um recipiente,
//encher um recipiente,
//derramar água de um recipiente para o outro, sem derramar, até que um dos recipientes esteja cheio ou vazio.
int solve(int init, int destiny, int expected){
    int cp1 = 0, cp2 = 0, aux;
    int ans =0;
    set<pair<int, int>> processed;
    while(1){
        if(cp1 == expected || cp2 == expected)return ans;
        if(cp1 == 0)cp1 = init;
        else if(cp2 == destiny) cp2 = 0;
        else{    
            aux = cp2;
            cp2 = min(cp2+cp1,destiny);
            cp1 -= cp2-aux;
        }
        if(processed.find({cp1, cp2}) != processed.end())return -1;
        processed.insert({cp1, cp2});
        ans++;
    }
}

int main(){
    int cases;scanf("%d", &cases);
    for(int i =0;i<cases;i++){
        int mc1, mc2, expected;
        scanf("%d%d%d", &mc1, &mc2, &expected);
        int ans1 = solve(mc1, mc2, expected);
        int ans2 = solve(mc2, mc1, expected);
        printf("%d\n", getMin(ans1, ans2));
    }

    return 0;
}