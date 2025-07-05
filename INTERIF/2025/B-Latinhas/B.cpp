#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, max, ans, c;
    scanf("%d", &n);
    while(n != 0){
        max = -1;
        ans = 0;
        for(int i =0; i<n; i++){
            scanf("%d", &c);
            if(c > max){
                ans = i+1;
                max = c;
            }
        }
        printf("%d\n", ans);
        scanf("%d", &n);
    }

    return 0;
}