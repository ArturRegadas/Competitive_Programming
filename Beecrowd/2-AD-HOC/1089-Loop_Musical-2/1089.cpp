#include <bits/stdc++.h>
using namespace std;

int MAXN = 10010;
int main(){
    int size, ans, first;
    int current, ant;
    bool up, fup;
    while(1){
        scanf("%d", &size);
        if(size == 0)return 0;
        ans = 0;
        scanf("%d", &ant);
        first = ant;
        up=false;
        fup = false;
        for(int i =1;i<size;i++){
            scanf("%d", &current);
            if(current>ant && (!up || i ==1)){
                if(i == 1)fup=true;
                ans++;
                up=true;
            }
            else if(current<ant && (up || i==1)){
                if(i == 1)fup=false;
                ans++;
                up=false;
            }
            ant = current;
        }
        if(first>ant && !up && !fup){
            ans++;
            up=true;
        }
        else if(first<ant && up && fup){
            ans++;
            up=false;
        }
        printf("%d\n", ans);

    }
}