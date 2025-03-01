#include <bits/stdc++.h>
using namespace std;

int main(){
    int size, ans; scanf("%d", &size);
    double num;
    for(int i =0;i<size;++i){
        scanf("%lf", &num);
        ans=0;
        while(num>1){
            num/=2;
            ans++;
        }
        printf("%d dias\n", ans);
    }

    return 0;
}