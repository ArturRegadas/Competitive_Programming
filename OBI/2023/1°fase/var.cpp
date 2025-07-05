#include <bits/stdc++.h>
using namespace std;

int main(){
    int x, y;
    scanf("%d%d", &x, &y);
    if((x <=8 && x >= - 8) && (y<=8 && y>=0)){
        printf("S\n");
    }
    else{
        printf("N\n");
    }

    return 0;
}