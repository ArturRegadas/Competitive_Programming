#include <bits/stdc++.h>
using namespace std;

int chinelos[510];

int main(){
    int n, p, c;
    scanf("%d", &n);
    for(int i =0; i<n; i++){
        scanf("%d", &chinelos[i+1]);
    }
    scanf("%d", &p);
    int ans = 0;
    for(int i =0; i<p; i++){
        scanf("%d", &c);
        if(chinelos[c] > 0){
            chinelos[c]--;
            ans++;
        }
    }
    printf("%d\n", ans);

    return 0;
}