#include <bits/stdc++.h>
using namespace std;

set<string> getDiagonais(int x1, int y1){
    int ax1, ay1;
    set<string> ans;
    ax1 = x1;
    ay1= y1;
    for(int i =0;i<=8;++i){
        ax1++;
        ay1++;
        ans.insert(to_string(ax1)+ to_string(ay1));
    }
    ax1 = x1;
    ay1= y1;
    for(int i =0;i<=8;++i){
        ax1--;
        ay1++;
        ans.insert(to_string(ax1)+ to_string(ay1));
    }
    ax1 = x1;
    ay1= y1;
    for(int i =0;i<=8;++i){
        ax1--;
        ay1--;
        ans.insert(to_string(ax1)+ to_string(ay1));
    }
    ax1 = x1;
    ay1= y1;
    for(int i =0;i<=8;++i){
        ax1++;
        ay1--;
        ans.insert(to_string(ax1)+ to_string(ay1));
    }
    return ans;

}

int main(){
    int x1, x2, y1, y2;
    while(true){
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if(x1==0 && x2 ==0 && y1 ==0 && y2 ==0)return 0;
        if(x1 == x2 && y1 == y2){
            printf("0\n");
            continue;
        }
        set<string>diagonais = getDiagonais(x1, y1);
        if(x1 == x2 || y1 == y2 || diagonais.find(to_string(x2)+to_string(y2)) != diagonais.end()){
            printf("1\n");
            continue;
        }
        printf("2\n");
    }
}