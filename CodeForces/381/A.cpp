#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;

int nuns[MAXN];

int main(){
    int size;scanf("%d", &size);
    for(int i =0;i<size;i++)scanf("%d", &nuns[i]);
    int l =0, r=size-1;
    bool sereja = true;
    int ansS =0, ansD =0;
    for(int i =0;i<size;i++){
        if(nuns[l]>=nuns[r]){
            if(sereja)ansS+=nuns[l];
            else ansD+=nuns[l];
            l++;
        }
        else{
            if(sereja)ansS+=nuns[r];
            else ansD+=nuns[r];
            r--;
            
        }
        sereja = !sereja;
    }
    printf("%d %d\n", ansS, ansD);

    return 0;
}