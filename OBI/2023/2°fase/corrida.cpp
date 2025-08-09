#include <iostream>
#include <utility>
#define INF 1000000
using namespace std;

int main(){
    int n, d;
    int maxA = 0, minA = INF;
    int maxL = 0, minL = INF;
    int curA, curL;
    char l;
    scanf("%d", &n);
    curA = 0;
    curL = 0;
    for(int i =0; i<n; i++){
        scanf("%d %c", &d, &l);
        if(l == 'N')
            curA+=d;
        else if(l == 'S')
            curA-=d;
        else if (l == 'L')
            curL +=d;
        else
            curL-=d;
        maxA = max(maxA, curA);
        minA = min(minA, curA);
        maxL = max(maxL, curL);
        minL = min(minL, curL);
    }
    printf("%d\n", 2*(maxA - minA+2) + 2*(maxL-minL+2));
    return 0;
}