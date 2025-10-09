#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int ans = 0;
    for(int i =1 ; i<=m; i+=5){
        ans++;
    }
    if(ans < n)
        printf("N\n");
    else 
        printf("S\n");
}