#include <bits/stdc++.h>
using namespace std;

bool findS(char t, string s1){
    for(char i : s1){
        if(i==t)
            return true;
    }
    return false;
}

int main(){
    int n,m;
    scanf("%d%d", &n, &m);
    string s1, s2;
    cin>>s1>>s2;

    bool ans = true;
    for(char i : s2){
        if (!findS(i, s1)){
            ans = false;
            break;
        }
    }
    if(ans)
        printf("S\n");
    else
        printf("N\n");
    return 0;
}