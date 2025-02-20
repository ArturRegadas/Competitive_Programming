#include <bits/stdc++.h>
using namespace std;

int main(){

    int d, t, ax;scanf("%d%d", &d, &t);
    int days[d];
    for(int i =0;i<d;i++){
        scanf("%d", &ax);
        days[i] = ax;
    }
    int ans =0;
    int nextL, currentL;
    currentL = nextL = days[0];
    bool flag = false;
    for(int i=1;i<d;i++){
        if(currentL > days[i] && (currentL - days[i] >= t) || days[i] < nextL ){
            ans = max(ans, ans + currentL - nextL - t);
            currentL = nextL = days[i];
        }
        if(days[i]>currentL){
            currentL = days[i];
        }
    }

    ans = max(ans, ans + currentL - nextL - t);
    
    printf("%d\n", max(0, ans));


    return 0;
}