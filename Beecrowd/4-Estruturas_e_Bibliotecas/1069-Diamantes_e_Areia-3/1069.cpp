#include<bits/stdc++.h>
using namespace std;

int main(){
    int open, ans;
    int repeat;scanf("%d", &repeat);
    string command;
    for(int r =0;r<repeat;++r){
        ans = open = 0;
        cin>>command;
        for(char i : command){
            if(i=='<'){
                open++;
           }
            if(i=='>' && open>0){
                open--;
                ans++;
            }
        }
        printf("%d\n", ans);
    }


    return 0;
}