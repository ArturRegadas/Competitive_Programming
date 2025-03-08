#include <bits/stdc++.h>
#define MAXN (int)1e5+10
using namespace std;

int nuns[MAXN], processed[MAXN] = {0};

int main(){
    int size;
    scanf("%d", &size);
    for(int i =0;i<size;i++)scanf("%d", &nuns[i]);
    int minus;
    int l = 0, r=size-1;
    processed[r] = 2;
    processed[l] = 1;
    int alice = 0, bob = 0;
    while(l<=r){
        if(l==r && processed[l]==1){alice++;break;}
        else if (l == r){bob++;break;}

        minus=min(nuns[l], nuns[r]);
        nuns[l]-=minus;
        nuns[r]-=minus;
        if(nuns[l] == 0){
            alice++;
            l++;
            if(processed[l]==0)processed[l] = 1;
        }
        if(nuns[r] == 0){
            bob++;
            r--;
            if(processed[r]==0)processed[r] = 2;
        }
    }
    printf("%d %d\n", alice, bob);
    return 0;
}