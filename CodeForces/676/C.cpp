#include <bits/stdc++.h>
using namespace std;

int a, b;
string sequence;

int getBealtiful(char c){
    int l = 0;
    int r = 0;
    int used =0;
    int ans = 0;
    int current =0;
    for(;l<a;l++){
        while(r<a && (used<b || sequence[r] == c)){
            if(sequence[r] != c)used++;
            ++r;
        }
        if(sequence[l]!=c)used--;
        ans = max(ans, r-l);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>a>>b>>sequence;
    int bealtifulA = getBealtiful('a');
    int bealtifulB = getBealtiful('b');
    printf("%d\n", max(bealtifulA, bealtifulB));
    
    return 0;
}