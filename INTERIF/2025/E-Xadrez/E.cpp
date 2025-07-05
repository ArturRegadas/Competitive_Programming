#include <bits/stdc++.h>
using namespace std;

int main(){

    int x1, y1, x2, y2;
    int px, py;
    while(true){
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if(x1 == 0)
            break;

        x1--;y1--;x2--;y2--;
        px = x1;
        py = y1;
        int ans = false;
        while(px < 8 && py < 8){
            if(px == x2 && py == y2)
                ans = true;
            px++;
            py++;
        }
        
        px = x1;
        py = y1;
        while(px < 8 && py >= 0){
            if(px == x2 && py == y2)
                ans = true;
            px++;
            py--;
        }
        px = x1;
        py = y1;
        while(px >= 0 && py >= 0){
            if(px == x2 && py == y2)
                ans = true;
            px--;
            py--;
        }
        px = x1;
        py = y1;
        while(px >= 0 && py < 8){
            if(px == x2 && py == y2)
                ans = true;
            px--;
            py++;
        }
        if(ans){
            printf("Possible\n");
        }
        else{
            printf("Impossible\n");
        }
        
    }

    return 0;
}