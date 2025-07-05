#include <bits/stdc++.h>
using namespace std;

int sa[100010];
int sb[100010];

int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    for(int i =0; i<a;i++)scanf("%d", &sa[i]);
    for(int i =0; i<b;i++)scanf("%d", &sb[i]);

    int sbi = 0;

    bool ans = false;
    for(int i =0; i<a;i++){
        if(sa[i] == sb[sbi]){
            sbi++;
            if(sbi >= b){
                ans = true;
                break;
            }
        }
    }
    if(ans)
        printf("S\n");
    else
        printf("N\n");

    return 0;
}